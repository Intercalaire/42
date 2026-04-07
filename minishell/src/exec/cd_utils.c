void	env_update(t_data *data, char *oldpwd)
{
	char	*newpwd;

	newpwd = ft_calloc(PATH_MAX, sizeof(char));
	getcwd(newpwd, PATH_MAX);
	if (search_env(data, "OLDPWD") == -1)
		add_env(data, "OLDPWD", oldpwd);
	else
		change_env(data, "OLDPWD", oldpwd);
	if (search_env(data, "PWD") == -1)
		add_env(data, "PWD", newpwd);
	else
		change_env(data, "PWD", newpwd);
	free(newpwd);
	free(oldpwd);
}
