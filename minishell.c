/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:11:52 by kbrener-          #+#    #+#             */
/*   Updated: 2024/05/16 14:11:55 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>


int main(void)
{
	char	*input;

	while ((input = readline("prompt> ")) != NULL)
	{
		if (input[0] != '\0')
		{
			add_history(input);
		}
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}
		printf("You entered: %s\n", input);
		free(input); // Libère la mémoire allouée pour la ligne
	}
	return 0;
}
