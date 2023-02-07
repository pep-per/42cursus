// static char	*load_backup(t_link *curr, ssize_t *newline_idx)
// {
// 	char	*str;

// 	*newline_idx = find_newline(curr->backup, curr->backup_len);
// 	if (*newline_idx == NO_NEWLINE)
// 		return (0);
// 	str = ft_strdup(curr->backup, *newline_idx + 1);
// 	if (!str)
// 		return (0);
// 	return (str);
// }

static void	save_backup(t_link *curr, char *buf, ssize_t read_num, \
												ssize_t newline_idx)
{
	if (read_num == 0)
	{
		curr->backup = &curr->backup[newline_idx + 1];
		curr->backup_len -= (newline_idx + 1);
	}
	else
	{
		curr->backup = &buf[newline_idx + 1];
		curr->backup_len = read_num - (newline_idx + 1);
	}
}

static char	*make_line(t_link *curr, char *line, char *buf, ssize_t read_num)
{
	ssize_t			newline_idx;

	newline_idx = NO_NEWLINE;
	if (curr->backup == NULL && read_num == 0)
		return (0);
	if (curr->backup)
	{
		newline_idx = find_newline_or_eof(curr->backup, curr->backup_len);
		if (newline_idx != NO_NEWLINE)
			return (ft_strdup(curr->backup, newline_idx + 1));
	}
	ft_bzero(buf, BUFFER_SIZE + 1);
	if (read_num > 0)
		newline_idx = find_newline_or_eof(buf, read_num);
	save_backup(curr, buf, read_num, newline_idx);
	if (read_num == 0)
		return (line);
	if (!line)
		return (ft_strdup(buf, read_num));
	return (ft_strjoin(line, buf, read_num));
}