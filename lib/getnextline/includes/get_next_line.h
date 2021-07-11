/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:10:02 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:10:03 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "utils.h"
# define BUFFER_SIZE 1

char		*search(int fd, char **rest, int *ret);
int			get_next_line(int fd, char **line);
int			find(char **line, char **rest, int retn);
#endif
