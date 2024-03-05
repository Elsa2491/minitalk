void    ft_send_bits(pid_t pid, char c)
{
    int    bit;

    bit = 0;
    while (bit < 8)
    {
        if (c & (1 << bit))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(200);
        bit += 1;
    }
}

void    send_message(pid_t pid, char *msg)
{
    int    i;

    i = 0;
    while (msg[i])
    {
        send_bits(pid, msg[i]);
        i++;
    }
    send_bits(pid, ' ');
}

int    main(int argc, char **argv)
{
    pid_t    pid;
    int        i = 2;

    if (argc <= 2)
    {
        ft_printf(RED"Error: invalid arguments.\n");
        ft_printf(YELLOW
            "Try this instead: ./client <SERVER_PID> <MESSAGE>\n");
        return (1);
    }
    while (i < argc && ft_strisnum(argv[1]) && argv[i][0] != '\0')
    {
        pid = ft_atoi(argv[1]);
        if (pid > 0)
            send_message(pid, argv[i++]);
        else
            ft_printf(BOLD RED"Wrong PID!\n");
    }
    send_bits(pid, '\n');
    return (EXIT_SUCCESS);
}

/*

	if (argc !=)	1 - on stock le pid_server
		c'est un int -> convertir en char
		itoa(getpid());
	2 - quelque soit la valeur de argv[1], argv[1] = pid_server (converti en char)
		ici on fait un strcmp, si ça return 1
			ici on écrase argv[1], quelle que soit sa valeur
		sinon
			ici on écrase argv[1], quelle que soit sa valeur
	3 - reconverti pid_server_char -> en int
		atoi(argv[1]);
	
}*/
