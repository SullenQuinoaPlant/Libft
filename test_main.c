/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:43:54 by nmauvari          #+#    #+#             */
/*   Updated: 2018/01/28 06:46:19 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "h.h"
#include <limits.h>


int		main(int ac, char **av)
{
	(void) ac;
	(void) av;

#ifdef NO_TEST
	printf("no function selection was made");
#elif ATOI
	if (ac == 2)
	{
		printf("atoi is : %d\n", atoi(av[1]));
		printf("\nft_atoi is :%d", ft_atoi(av[1]));
	}
	else
	{
		//char	*str = "\t\v\r\f\n \t-  456";
		char	*str = "";
		char	n[40];

		sprintf(n, "%li", LONG_MAX);
		printf("value stored at n is :%s\n", n);

		int		ret_ft = ft_atoi(n);
		int		ret = atoi(n);
		printf("\nft_atoi of n gives: %d, atoi gives : %d\n", ret_ft, ret);
		
		printf("long max value is : %li", LONG_MAX);
		printf("atoi is : %d\n", atoi(str));
		printf("\nft_atoi is :%d", ft_atoi(str));
	}
#elif ISALPHA
	int		i;

	i = -300;
	while (i < 300)
	{
		if (isalpha(i) != ft_isalpha(i))
			printf("error at %d, isalpha: %d, ft_isalhpa: %d\n", i, isalpha(i),\
				   		ft_isalpha(i));
		i++;
	}
#elif ISALNUM
	int		i;
	i = -1;
	while (i < 530)
	{
		if (!!ft_isalnum(i) != !!isalnum(i))
			printf("/nisulnum failed on: %d,\
					ft_isalnum : %d,\
					isalnum : %d,\
					!!ft_isalnum: %d,\
					!!isalnum: %d\n", i, ft_isalnum(i), isalnum(i), !!ft_isalnum(i), !!isalnum(i));
		i++;
	}
#elif ITOA
	if (ac == 2)
	{
		int	i;
		char	*a;

		i = atoi(av[1]);
		a = ft_itoa(i);
		printf("\nprintf gives: %d, ft_itoa gives: %s", i, a);
		free(a);
	}
	else
		printf("test of ft_itoa requires exactly one arument");
#elif LSTDEL
	void	del(void *content, size_t size)
	{
		(void)size;
		free(content);
	}
	void	print(t_list *elem)
	{
		printf("\nfrom print, as string: %s", (char*)(elem->content));
	}
	void	lwrite(t_list *elem)
	{
		write(1, "\nin dummy", strlen("\nin dummy") + 1);
		write(1, (char*)elem->content, 1);
	}
	void	nowrite(t_list *foff)
	{
		(void)foff;
	}
	void	dummy(void *content, size_t size)
	{
		(void)content;
		(void)size;
	}
	t_list	*head;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	head = 0;
	a = ft_lstnew("a", 2);
	printf("\n address stored at a is :%lu", (unsigned long)a);
	b = ft_lstnew("b", 2);
	printf("\n address stored at b is :%lu", (unsigned long)b);
	c = ft_lstnew("c is special", 13);
	printf("\n address stored at c is :%lu", (unsigned long)c);
	ft_lstadd(&head, c);
	ft_lstadd(&head, b);
	ft_lstadd(&head, a);
	if (1)
	{
		printf("\n head gives: %s", head ? (char*)head->content : "head set to null");
		printf("\na: %s, b: %s, c: %s",\
				 (a ? (char*)a->content : "a del"),\
				 (b ? (char*)b->content : "b del"),\
				 (c ? (char*)c->content : "c del"));
	}
	printf("\n starting to delete\r");
	printf("\n address stored at head is :%lu", (unsigned long)head);
	printf("\n address stored at a is :%lu\n", (unsigned long)a);
	delthis(&head, &del);
	delthis(&a, &del);
//	ft_lstdel(&head, &del);
	printf("\n address stored at head is :%lu", (unsigned long)head);
	printf("\n address stored at a is :%lu\n", (unsigned long)a);
	free(a);
	printf("\n address stored at a is :%lu\n", (unsigned long)a);
//	ft_lstdel(&head, &del);
//	delthis(&head);
//	delthis(&head);
//	free(a);
	void	stupiddel(t_list **delthis)
	{
		free(*delthis);
	}
//	delthis(&a);
//	stupiddel(&a);
#elif MEMCMP
	int		ft_ret;
	int		ret;

	printf("memcmp test :\n");
	if (ac == 3)
	{
		ft_ret = ft_memcmp(av[1], av[2], strlen(av[1]));
		ret = memcmp(av[1], av[2], strlen(av[1]));
		if (ft_ret != ret)
			printf("\nyou fucked up");
	}
	else
	{
		ft_ret = ft_memcmp("aoeu", "mmm", 0);
		ret = memcmp("aoeu", "mmm", 0);
		if (ft_ret != ret)
		{
			printf("\nft_ret is : %d, \nret is : %d", ft_ret, ret);
			printf("\nyou fucked up");
		}
	}
#elif MEMCPY
	if (ac == 2)
	{
		char    *dest;
		size_t  length;

		length = strlen(av[1]);
		if (!(dest = malloc(length + 1)))
		{
			printf("malloc call failed, in MEMCPY test\n");
			return (0);
		}
		if ((length = strcmp(ft_memcpy(dest, av[1], length), av[1])))
		{
			printf("ft_memcpy failed. return val of strcmp is: %d", length);
		}
		free(dest);
	}
	else
		printf("ft_memcpy test requires exactly one argument");
#elif PUTNBR
	if (ac == 2)
	{
		int	t;

		t = atoi(av[1]);
		printf("printf gives : %d\t and putnbr gives: ", t);
		ft_putnbr(t);
	}
#elif STRNEQU
	if (ac == 4)
	{
		printf("\nreturn value of ft_strnequ(a1, a2) is : %d",\
			ft_strnequ(av[1], av[2], atoi(av[3])));
	}
	else
		printf("ft_strnequ test requires exactly three arguments:\
			string1, string2 and number of bytes to compare");
#elif STREQU
	if (ac == 3)
	{
		printf("\nreturn value of ft_strequ(a1, a2) is : %d",\
			ft_strequ(av[1], av[2]));
	}
	else
		printf("ft_strequ test requires exactly two strings as arguments");
#elif STRITER
	if (ac == 2)
	{
		void	here_f(char *c)
		{
			*c = 'h';
		}
		ft_striter(av[1], here_f);
		printf("\nresult of ft_striter is :\n%s", av[1]);
	}
	else
		printf("test of ft_striter requires exactly one argument");
#elif STRITERI
	if (ac == 2)
	{
		void	here_f(unsigned int i, char *c)
		{
			i % 2 ? *c = 'h' : (1);
		}
		ft_striteri(av[1], here_f);
		printf("\nresult of ft_striter is :\n%s", av[1]);
	}
	else
		printf("test of ft_striteri requires exactly one argument");
#elif STRJOIN
	if(ac == 3)
	{
		char	*s;

		s = ft_strjoin(av[1], av[2]);
		printf("\nresult of ft_strjoin(av[1], av[2]) is : %s", s);
	}
#elif STRMAP
	if (ac == 2)
	{
//		char	*s;
//		char	here_f(char c)
//		{
//			return (c + 1);
//		}
//
//		s = ft_strmap(av[1], here_f);
//		printf("\nresult of ft_strmap is :\n%s", s);
//	}
//	else
//		printf("test of ft_strmap requires exactly one argument");
#elif STRNCMP
	int		ft_ret;
	int		ret;

	if (ac == 3)
	{
		ft_ret = ft_strncmp(av[1], av[2], strlen(av[1]));
		ret = strncmp(av[1], av[2], strlen(av[1]));
		if (ft_ret != ret)
			printf("\nyou fucked up");
	}
	else
	{
		ft_ret = ft_strncmp("aoeu", "mmm", 0);
		ret = strncmp("aoeu", "mmm", 0);
		if (ft_ret != ret)
		{
			printf("\nft_ret is : %d, \nret is : %d", ft_ret, ret);
			printf("\nyou fucked up");
		}
	}
#elif STRNCPY
	if (ac == 3)
	{
		char	*src = "--> nyancat <--\n\r";
		char	dst1[30];
		char	dst2[30];
		size_t	max = 12;

		memset(dst1, 'B', sizeof(dst1));
		memset(dst2, 'B', sizeof(dst2));

		strncpy(dst1, src, max);
		ft_strncpy(dst2, src, max);
		if (memcmp(dst1, dst2, 29)){
			printf("\ndst1 and dst2 are not identical");
		}
		char	*n;
		char	*nn;
		char	*rn = 0;
		char	*rnn = 0;
		size_t	l;
		char	ar[100];
		char	arr[100];

		(void)rn;
		(void)rnn;

//		l = (size_t)atoi(av[2]);
		l = strlen(src);
//		l = 2;
		memset(ar, 0, 99);
		memset(arr, 0, 99);
		write(1, "hey", 3);
		printf("\n l is : %lu", (unsigned long)l);
		n = strncpy(ar, (const char*)src, l); 
		nn = ft_strncpy(arr, (const char*)src, l);
		printf("\nstring copied from ft_strncpy is: %s", nn);
		if (memcmp(n, nn, l))
			printf("\n results not equal");
	}
	else
		printf("\nstrncpy test requires exactly 2 arguments");
#elif STRSUB
	if (ac == 4)
	{
		char	*s;

		s = ft_strsub(av[1], atoi(av[2]), atoi(av[3]));
		printf("\nreturned string is: %s", s);
	}
#elif MEMALLOC
	if (ac == 2)
	{
		void	*new_buff;
		int		size;

		size = atoi(av[1]);
		new_buff = ft_memalloc(size);
		if (!new_buff)
			return (1);
		while (size--)
			if (((char*)new_buff)[size])
				printf("\nmemalloc failed, found a byte at : %c",\
					 ((char*)new_buff)[size]);
		free(new_buff);
	}
	else
		printf("memalloc test requires one numeric argument");
#elif STRRCHR
	if (ac == 3)
	{
		printf("\nargument 1 is: %s\nargument 2 is: %c", av[1], av[2][0]);
		if (ft_strrchr(av[1], (int)av[2][0]) == strrchr(av[1], (int)av[2][0]))
			printf("\nft_strrchr and strrchr returned same value");
	}
	else
		printf("ft_strrchr test requires exactly 2 arguments");
	return (0);
#elif STRSPLIT
	if (ac == 3)
	{
		char	**splits;

		splits = ft_strsplit(av[1], av[2][0]);
		while (*splits)
		{
			printf("\n%s",*splits++);
		}
	}
	else
		printf("\nft_strsplit test requires exactly two arguments.");
#elif STRTRIM
	char	*ret_str;

	if (ac == 2)
	{
		ret_str = ft_strtrim(av[1]);
		printf("\nret_str is :%s\n", ret_str);
		free(ret_str);
	}
	else
	{
		ret_str = ft_strtrim("\n\t AAA \t BBB \t\n");
		printf("\nret_str is :%s\n", ret_str);
		free(ret_str);
	}
#else
	printf("no function selection was made");
#endif
	return (0);
}
