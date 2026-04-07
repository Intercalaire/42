# Vault Security Hardening Guide

## 🚨 Critical Issues Fixed

### 1. **Root Token Exposure**
- **Before:** ROOT_TOKEN exported as environment variable globally
- **After:** Token stored in secure file with 0600 permissions, only loaded when needed

### 2. **AppRole Credentials Persistence**
- **Before:** role_id.txt, secret_id.txt written with default permissions (777/644)
- **After:** All credentials written with 0600 (read/write owner only), then unset from memory

### 3. **Wrapping Token Cleanup**
- **Before:** token stored without size restriction or automatic removal
- **After:** Stored with 0600 permissions, configured to auto-delete after reading

### 4. **SecureID Auto-Removal**
- **Before:** `remove_secret_id_file_after_reading=false`
- **After:** `remove_secret_id_file_after_reading=true`

### 5. **Git History Leaks**
- **Before:** No .gitignore protection for vault/file directory
- **After:** Comprehensive .gitignore with critical secret patterns

## ✅ Security Checklist

Before deploying:

- [ ] Run `bash scripts/cleanup_git_secrets.sh` to audit git history
- [ ] Rotate ALL Vault tokens immediately
- [ ] Review docker-compose volumes to ensure /vault/file is not mounted insecurely
- [ ] Set VAULT_ADDR to HTTPS only (no HTTP in production)
- [ ] Enable audit logging in Vault
- [ ] Implement network policies to restrict Vault access
- [ ] Use secrets-bot or CI/CD tool to manage secrets injection
- [ ] Never store init.json in version control

## 🔐 Best Practices

### Permissions Model
```bash
# After secret generation:
chmod 0600 /vault/file/role_id.txt      # Read/write owner only
chmod 0600 /vault/file/secret_id.txt    # Read/write owner only
chmod 0600 /vault/file/wrapping_token.txt  # Read/write owner only
```

### Token Lifecycle
```bash
# 1. Generate token
TOKEN=$(vault read -field=x auth/approle/role/myapp/role-id)

# 2. Store securely
printf "%s" "$TOKEN" > /vault/file/token.txt
chmod 0600 /vault/file/token.txt

# 3. Use token
export VAULT_TOKEN="$(cat /vault/file/token.txt)"

# 4. Clear from memory
unset VAULT_TOKEN
```

### Vault Agent Configuration
- Set `remove_secret_id_file_after_reading = true`
- Use response wrapping with short TTLs (5m)
- Configure sink files with appropriate permissions
- Rotate AppRole credentials regularly

## 📋 Files Modified

1. `infrastructure/vault/init_unseal.sh` - Secure ROOT_TOKEN handling
2. `infrastructure/vault/vault_config.sh` - Secure AppRole credentials
3. `infrastructure/vault/config/agent.hcl` - Enable auto-cleanup
4. `.gitignore` - Prevent secret commits

## 🔄 Rotation Schedule

- **AppRole RoleID:** Every 30 days
- **AppRole SecretID:** Every 24 hours  
- **Wrapping Tokens:** Every 5 minutes (auto by design)
- **Root Token:** Remove after initialization, use AppRole instead

## 📚 Resources

- [Vault AppRole Auth Method](https://www.vaultproject.io/docs/auth/approle)
- [Vault Agent Auto-Auth](https://www.vaultproject.io/docs/agent/autoauth)
- [OWASP: Secrets Management](https://owasp.org/www-community/attacks/Sensitive_Data_Exposure)
