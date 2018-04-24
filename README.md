# Libft
            
The libft project consists in recoding some functions of the C standard library. The project will be used for other projects as a base of useful functions.

# Available functions

### Memory functions 
```
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
size_t		ft_memchrindex(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);
int		**ft_int2alloc(size_t size, size_t len);
char		**ft_char2alloc(size_t size, size_t len);
void		**ft_memalloc2(size_t si1, size_t si2, size_t size);
void		ft_free2(void **tab);
void		*ft_memdup(const void *s, size_t i);
```
### Input/Output functions
```
void		ft_putchar(char c);
void		ft_putstr(const char *s);
void		ft_putendl(const char *s);
void		ft_putnbr(int nb);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
int		sget_next_char(const int fd, char **line, char c);
int		get_next_char(const int fd, char **line, char *buff, char c);
int		get_next_line(const int fd, char **line);
int		sget_next_line(const int fd, char **line);
```
# Mark (125%)
