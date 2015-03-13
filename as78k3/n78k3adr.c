/*
 *  Copyright (C) 2014-2015  Neil Johnson
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "asxxxx.h"
#include "n78k3.h"

#if 0
/*********  INFORMATION  *************************************/
/*
 *      The exp structure is used to return the evaluation
 *      of an expression.  The structure supports three valid
 *      cases:
 *      (1)     The expression evaluates to a constant:
 *                 mode = S_USER
 *                 flag = 0
 *                 addr = the constant
 *                 base = NULL.
 *      (2)     The expression evaluates to a defined symbol
 *              plus or minus a constant:
 *                 mode = S_USER
 *                 flag = 0
 *                 addr = the constant
 *                 base = pointer to area symbol.
 *      (3)     The expression evaluates to a external
 *              global symbol plus or minus a constant:
 *                 mode = S_NEW
 *                 flag = 1
 *                 addr = the constant
 *                 base = pointer to symbol.
 */
struct  expr
{
        char    e_mode;         /* Address mode */
        char    e_flag;         /* Symbol flag */
        a_uint  e_addr;         /* Address */
        union   {
                struct area *e_ap;
                struct sym  *e_sp;
        } e_base;               /* Rel. base */
        char    e_rlcf;         /* Rel. flags */
};
#endif

/****************************************************************************/
/*
 * Read an address specifier. Pack the address information into the supplied
 * `expr' structure. Return the mode of the address.
 *
 * This addr(esp) routine performs the following addressing decoding:
 *
 *	address		mode		flag		addr		base
 *	#n		    S_IMMED		0		    n		    NULL
 *	label		s_type		----		s_addr		s_area
 *	[REG]		S_IND+icode	0		    0		    NULL
 *	[label]		S_INDM		----		s_addr		s_area
 *	offset[REG]	S_IND+icode	----		offset		----
 */

#ifdef OTHERSYSTEM
int addr( struct expr *esp )
#else
int
addr(esp)
struct expr *esp;
#endif
{

    /* int c = getnb() -- returns next byte character from input file(s) */
    /* unget(c)        -- put c back into character stream */
    /* expr(esp, 0)    -- parses an expression, put into "esp".  The '0' is required. */





    
    return (esp->e_mode);
}

/****************************************************************************/

