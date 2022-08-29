/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:44:32 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/08/29 14:53:14 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}

int ft_strncmp(char *s1, char *s2)
{
    int i = 0;

    while(s1[i] && s2[i] && s1[i] == s2[i])
    {
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}


int main(int argc, char **argv, char **env)
{
    int i = 1;
    while(i < argc)
    {
        if(ft_strncmp(argv[i], ";") == 0)
        {
            printf("Semicolon detected\n");
        }else if(ft_strncmp(argv[i], "|") == 0)
        {
            printf("Pipe detected\n");
        }else{
            printf("%s\n", argv[i]);
            if(execve(argv[i], &argv[i], env) < 0)
            {
                write(2, "error: cannot execute", 22);
            };
        }
        i++;
    }
    return 0;
}