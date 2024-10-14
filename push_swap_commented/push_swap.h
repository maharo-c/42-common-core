#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

long		input_is_correct(char	*str);
int			is_sorted(t_stack *stack);
int			is_duplicated(t_stack *column);
void		get_numbers(char *argv, t_stack **stack_a);
void		get_index(t_stack *stack_a, int stack_size);
void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
void		error_exit(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
size_t		ft_strlen(const char *s);
int			count_words(char *str);
char		*ft_strncpy(char *dst, char *src, int size);
char	    **ft_split(char *str);
int			get_stack_size(t_stack *stack);
t_stack		*get_bottom(t_stack *stack);
t_stack		*before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add(t_stack **stack, t_stack *new);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		sort_three(t_stack **stack);
void		push_init(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);
int			position_lowest_index(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
int			ft_abs(int	nb);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);
void		cost(t_stack **stack_a, t_stack **stack_b);
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);



#endif