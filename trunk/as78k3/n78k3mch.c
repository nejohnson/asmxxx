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

/****************************************************************************/

char *cpu = "NEC 78K3 Series";
char *dsft = "asm";

int	mchtyp;

/****************************************************************************/
/**
    Process a machine instruction.

    mp      Pointer to a machine instruction
**/
#ifdef OTHERSYSTEM
VOID machine( struct mne *mp )
#else
VOID
machine(mp)
struct mne *mp;
#endif
{
    int opcode;
#if 0
    int t1, t2;
#endif
    struct expr e1, e2;
    int insn;

    printf("%d: mp->m_type = %d\n", pass, mp->m_type);
    printf("%d: mp->m_valu = %d\n", pass, mp->m_valu);

    clrexpr( &e1 );
    clrexpr( &e2 );
    opcode = mp->m_valu;
    insn   = mp->m_type;
	
    switch (insn)
    {
    case S_CPU:
        mchtyp = opcode;
        sym[2].s_addr = opcode;
        lmode = SLIST;
        break;

    /* Simple opcodes: 1 byte, no operands */
    case S_EI: case S_DI: case S_NOP: case S_BRK: case S_RET: case S_RETI: case S_ADJ4:
        outab( opcode );
        break;

    /* The mighty MOV */
#if 0
    /* work in progress */
    case S_MOV:
        t1 = addr(&e1);
        comma(1);
        t2 = addr(&e2);
        

        break;
#endif

    /* Catch anything else and flag error. */
    default:
        err('o');
        break;
    } /* switch(rf) */

}

/****************************************************************************/
/**
    Initialise the machine code generator.
**/
#ifdef OTHERSYSTEM
VOID minit( void )
#else
VOID
minit()
#endif
{
    if (pass == 0) {
        mchtyp = X_UPD78310;
        sym[2].s_addr = X_UPD78310;
    }
}

/****************************************************************************/

