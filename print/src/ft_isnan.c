/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

int	is_nan(double nbr)
{
	if (nbr != nbr)
		return (1);
	else
		return (0);
}
