#include "shell.h"

/**
 * get_history_file - it fetches the history file
 * @info: its a parameter struct
 * Return: allocated string containing the history file 
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (strlen(dir) + _strlen(HIST_FILE) +2));
	if (!buf)
		retrn (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - it creates a file, or adds to an existing file
 * @info: its a parameter struct 
 *
 * Return: 1 on success, else -1
 O*/

int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNIC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return(-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}


/**
 * read_history - it reads the history from the file 
 * @info - its a parameter struct
 *
 * Return: histcount on success, otherwise 0 
 */

int read_history(info_t *info)
{
	int i, last = 0,linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char =buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] =0;
	if (rdlen <= 0)
		return (free(bu), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buff[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info>histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - it adds entry to a linked history list 
 * @info: It is a structure containing potential arguments and is used to maintain
 * @buf: is a buffer
 *
 * REturn: 0 Always
 */

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if(!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - it renumbers the linked history list after changes
 * @info: Its a structure containing potential arguments
 *
 * Return: the new histcount
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while  (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
