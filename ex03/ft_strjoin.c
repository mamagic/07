#include <stdlib.h>


int len(char* str)
{
	    int     i;
	    i = 0;
		    while (str[i] != '\0')
				        i++;
			    return i;
}

char *size_zero(void)
{
	    char* result;
		    result = (char*)malloc(1);
			    result[0] = '\0';
				    return result;
}

char* ft_strjoin(int size, char** strs, char* sep)
{
    int i;
	    int j;
		    char* result;
			    int result_index;

					    i = 0;
						    result_index = 0;
							    if (size <= 0)
									        return size_zero();
								    result = (char*)malloc(sizeof(char) * (size + (len(sep) * size) - len(sep)) + 1);
									    if (!result)
											        return NULL;
										    while (i < size)
												    {
														        j = 0;
																        while (strs[i][j] != '\0')
																			            result[result_index++] = strs[i][j++];
																		        j = 0;
																				        while (sep[j] != '\0' && i != size - 1)
																							            result[result_index++] = sep[j++];
																						        i++;
																								    }
											    result[result_index] = '\0';
												    return result;
}
