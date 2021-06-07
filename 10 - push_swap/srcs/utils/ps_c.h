#ifndef PS_C_H
# define PS_C_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				s;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

//			ARGS.C
t_stack		**ft_execargs(t_stack **stack, char	*arg);
char		**ft_divideargs(char **args, char *aux);
char		**ft_readargs(void);
void		ft_printargs(char **args);
char		**ft_putlastarg(char **args, char *command);

//			CHUNKS.C
int			*ft_invertchunk(int *chunk);
int			*ft_orderchunk(t_stack *stack, int *chunk);
int			*ft_invertchunkno(int *chunk, int num);
int			*ft_whilechunk(t_stack *stack, int *chunk, int i, int x);
int			*ft_findchunk(t_stack *stack);

//			CHUNKSUTILS.C
int			ft_chunksize(int *chunk);
int			ft_isinchunk(int *chunk, int num);
int			ft_highestinchunk(int *chunk, int ls);
int			ft_lastchunkappearance(int *chunk, t_stack *stack, int listsize);
int			ft_firstchunkappearance(int *chunk, t_stack *stack, int listsize);

//			NODEUTILS.C
t_stack		*ft_addfirst(t_stack *stack, t_stack *node);
t_stack		*ft_addlast(t_stack *stack, t_stack *node);
t_stack		*ft_penultnode(t_stack *stack);
t_stack		*ft_dellastnode(t_stack *stack);
t_stack		*ft_mallocnextnode(t_stack *stack);

//			NODEUTILS2.C
t_stack		*ft_lastnode(t_stack *stack);
t_stack		*ft_dupvalnode(t_stack *stack);
t_stack		*ft_dupnode(t_stack *stack);
int			ft_positionvalue(t_stack *stack, int pos);
int			ft_isthereequal(t_stack *stack);

//			UTILS.C
int			ft_listsize(t_stack *stack);
int			ft_highestvalue(t_stack *stack);
int			ft_lowestvalue(t_stack *stack);
int			ft_isallright(t_stack **stack);
int			ft_fullofdigits(char *s);

//			COMMANDS.C
t_stack		**ft_aorb(t_stack *src, t_stack *dest, char c);
t_stack		**ft_push(t_stack *src, t_stack *dest, char c);
t_stack		*ft_reverse(t_stack *stack);
t_stack		**ft_rrr(t_stack **stack);

//			COMMANDS2.C
t_stack		*ft_rotate(t_stack *stack);
t_stack		**ft_rr(t_stack **stack);
t_stack		*ft_swap(t_stack *stack);
t_stack		**ft_ss(t_stack **stack);

//			INSERTION.C
int			ft_positionsdistance(int *pos);
char		**ft_finalinsertion(char **args, int *pos);
char		**ft_finalinsertion2(char **args, int *pos);

//			POSITION.C
char		ft_ifzero(t_stack *stack, int x, int y);
char		ft_ifone(t_stack *stack, int x, int y);
char		ft_ifmore(t_stack *stack, int x, int y);
int			ft_highestina(t_stack *stack);
int			ft_positionina(t_stack *stack, int x);

//			SORT.C
int			*ft_bestposition(t_stack **stack);
char		**ft_sortthree(char **args, t_stack **stack);
char		**ft_sortmore(char **args, t_stack **stack);
char		**ft_sort(char **args, t_stack **stack);

//			SORTUTILS.C
int			*ft_initposvar(t_stack **stack);
int			*ft_initauxvar(t_stack **stack, int y);
int			ft_numofop(int a, int b);
int			ft_returnvalueposition(t_stack *stack, int num);
int			*ft_copychunk(int *chunk, int ls);

//			STACK.C
int			ft_atoichecker(char *num);
char		*ft_argvtoline(char **av, int ac);
t_stack		**ft_initstack(int argc, char **argv);
t_stack		*ft_readstack(char *stack);
char		**ft_sendtothetopa(t_stack *stack, char **args, int *chunk, int ls);

//			STACKUTILS.C
t_stack		*ft_dupstack(t_stack *stack);
t_stack		**ft_dupstacks(t_stack **stack);
t_stack		**ft_stacktofindchunk(t_stack **stack);
void		ft_printstacks(t_stack **stack);
int			*ft_returnorderedlist(t_stack *stack);

#endif
