/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:54:46 by nmauvari          #+#    #+#             */
/*   Updated: 2018/01/28 06:46:52 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

# include "libft.h"

//# define ATOI 1
//# define ISALPHA 2
//# define ITOA 9
//# define LSTDEL 12
//# define MEMCPY 13
//# define PUTNBR 16
//# define STRRCHR 19
//# define STRITER 191
//# define STRITERI 192
//# define STRMAP 193
//# define STREQU 194
//# define STRNEQU 195
//# define STRSUB 196
//# define STRJOIN 197
//# define STRSPLIT 198
//# define STRTRIM 1981
//# define STRNCPY 199

void	delthis(t_list**, void(*f)(void*, size_t));
#endif
