/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:05:30 by mouad             #+#    #+#             */
/*   Updated: 2024/12/01 10:50:59 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t  ft_strlen(const char    *str)
{
    size_t i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}

char    *ft_strdup(const char   *str)
{
    if(!str)
    {
        return NULL;
    }

    size_t str_len = ft_strlen(str);

    char    *new_string = malloc(str_len + 1);

    if(!new_string)
    {
        return NULL;
    }

    size_t i;

    i = 0;
    while(str[i])
    {
        new_string[i] = str[i];
        i++;
    }
    new_string[i] = '\0';
    return (new_string);
}
char    *ft_strchr(const char    *str,int    c)
{
    if(!str)
    {
        return NULL;
    }

    size_t  i;

    i = 0;
    while(str[i])
    {
        if(str[i] == (char)c)
        {
            return (char *)&str[i];
        }
        i++;
    }
    if(c == '\0')
    {
        return (char *)&str[i];
    }
    return NULL;
}

char    *ft_strjoin(const char  *s1, const char *s2)
{
    if(!s1 && !s2)
    {
        return NULL;
    }
    if(!s1)
    {
        return ft_strdup(s2);
    }
    if(!s2)
    {
        return ft_strdup(s1);
    }
    
    int s1_len,s2_len,total_len,i,j;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    total_len = s1_len + s2_len;

    
    char    *allocated = malloc(total_len + 1);
    if(!allocated)
    {
        return NULL;
    }

    i = 0;
    while(s1[i])
    {
        allocated[i] = s1[i];
        i++;
    }

    j = 0;
    while(s2[j])
    {
        allocated[i] = s2[j];
        j++;
        i++;
    }
    allocated[i] = '\0';
    return (allocated);
}
char    *ft_substr(char *s,unsigned int start,size_t    len)
{
    if(!s)
    {
        return NULL;
    }
    size_t s_len = ft_strlen(s);

    if(start >= s_len)
    {
        return ft_strdup("");
    }
    size_t extract_len = s_len - start;
    if(extract_len > len)
    {
        extract_len = len;
    }
    char    *extract_string = malloc(extract_len + 1);
    
    if(!extract_string)
    {
        return NULL;
    }

    unsigned int i = start;
    unsigned int j = 0;
    while(j < extract_len)
    {
        extract_string[j] = s[i];
        j++;
        i++;
    }
    extract_string[i] = '\0';
    return (extract_string);
}