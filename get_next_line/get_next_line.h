/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:05:17 by mouad             #+#    #+#             */
/*   Updated: 2024/12/02 15:57:07 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

size_t  ft_strlen(const char    *str);
char    *ft_strdup(const char   *str);
char    *ft_strchr(const char    *str,int    c);
char    *ft_strjoin(const char  *s1, const char *s2);
char    *ft_substr(char *s,unsigned int start,size_t    len);
char    *get_next_line(int  fd);

#endif