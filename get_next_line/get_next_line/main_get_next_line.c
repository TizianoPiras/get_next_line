/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:26:00 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/16 13:46:55 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int main(int argc, char **argv)
{
    char    *cazzetto;
    int     fd;
    (void)argc;

    fd = open(argv[1], O_RDONLY);
    cazzetto = get_next_line(fd);
    printf("%s", cazzetto);
    return(0);
}
