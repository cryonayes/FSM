#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum State { Locked, Unlocked, SIZE_STATE } t_state;
typedef enum Event { Push, Coin, SIZE_EVENT } t_event;

char	*State_S[] = {
	[Locked]	= "Locked",
	[Unlocked]	= "Unlocked"
};

int	FSM[SIZE_STATE][SIZE_EVENT] = {
//   Push    Coin
	{Locked, Unlocked},		// Locked
	{Locked, Unlocked}		// Unlocked
};

t_state	next_state(t_state state, t_event event)
{
	return FSM[state][event];
}

int	main(int argc, char **argv)
{
	char	*line;
	t_state	state = Locked;
	
	while (true)
	{
		printf("State: %s\n\n", State_S[state]);
		line = readline(">");
		
		if (!strcmp(line, "push"))
			state = next_state(state, Push);
		else if (!strcmp(line, "coin"))
			state = next_state(state, Coin);
		else
			fprintf(stderr, "Unknown event\n");
	}
	free(line);
}
