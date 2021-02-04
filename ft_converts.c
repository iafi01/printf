int     ft_check_type(int c)
{
    return ((c == 'c') || (c == 's') || (c == 'i') || 
    (c == 'd') || (c == 'x') || (c == 'u') || (c == 'X'));
}
int     ft_check_flag(int c)
{
    return ((c == '0') || (c == '*') || (c == '.'));
}