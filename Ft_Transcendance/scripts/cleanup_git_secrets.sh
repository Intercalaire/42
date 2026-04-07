#!/bin/bash
# Script pour nettoyer les secrets Vault committé par accident
# Usage: bash cleanup_git_secrets.sh

set -eu

echo "🔍 Scanning git history for Vault secrets..."
echo "=============================================="

# Files to search for
SENSITIVE_FILES=(
  "role_id.txt"
  "secret_id.txt"
  "wrapping_token.txt"
  "root.token.tmp"
  "init.json"
  ".vault-token"
)

FOUND=0

for file in "${SENSITIVE_FILES[@]}"; do
  if git log --all --full-history -S "$file" --oneline 2>/dev/null | grep -q .; then
    echo "⚠️  FOUND: $file in git history"
    FOUND=1
  fi
done

if [ $FOUND -eq 1 ]; then
  echo ""
  echo "🚨 CRITICAL: Secrets found in git history!"
  echo "Follow these steps immediately:"
  echo ""
  echo "1. Rotate ALL Vault tokens and secrets"
  echo "2. Run: git filter-branch --force -f --prune-empty --index-filter \\"
  echo "   'git rm -rf --cached --ignore-unmatch role_id.txt secret_id.txt wrapping_token.txt init.json .vault-token' \\"
  echo "   --tag-name-filter cat -- --all"
  echo ""
  echo "3. Force push: git push origin --force --all && git push origin --force --tags"
  echo "4. Ask all team members to re-clone the repository"
  echo ""
else
  echo "✅ No Vault secrets found in git history"
fi

echo ""
echo "Checking current working directory for uncommitted secrets..."
for file in "${SENSITIVE_FILES[@]}"; do
  if find . -name "$file" -type f 2>/dev/null | grep -v node_modules | grep -v ".git"; then
    echo "⚠️  Found local file: $file"
  fi
done
