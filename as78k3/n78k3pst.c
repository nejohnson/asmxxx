/* n78k3pst.c */

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

/*
 * Coding Banks
 */
struct	bank	bank[2] = {
    /*	The '_CODE' area/bank has a NULL default file suffix.	*/
    {	NULL,		"_CSEG",	NULL,		0,	0,	0,	0,	0	},
    {	&bank[0],	"_DSEG",	"_DS",		1,	0,	0,	0,	B_FSFX	}
};

/*
 * Coding Areas
 */
struct	area	area[2] = {
    {	NULL,		&bank[0],	"_CODE",	0,	0,	0,	A_1BYTE|A_BNK|A_CSEG	},
    {	&area[0],	&bank[1],	"_DATA",	1,	0,	0,	A_1BYTE|A_BNK|A_DSEG	}
};

/*
 * Basic Relocation Mode Definition
 *
 *	#define		R_NORM	0000		No Bit Positioning
 */
char	mode0[32] = {	/* R_NORM */
	'\200',	'\201',	'\202',	'\203',	'\204',	'\205',	'\206',	'\207',
	'\210',	'\211',	'\212',	'\213',	'\214',	'\215',	'\216',	'\217',
	'\220',	'\221',	'\222',	'\223',	'\224',	'\225',	'\226',	'\227',
	'\230',	'\231',	'\232',	'\233',	'\234',	'\235',	'\236',	'\237'
};

/*
 * Additional Relocation Mode Definitions
 */

/* None Required */

/*
 *     *m_def is a pointer to the bit relocation definition.
 *	m_flag indicates that bit position swapping is required.
 *	m_dbits contains the active bit positions for the output.
 *	m_sbits contains the active bit positions for the input.
 *
 *	struct	mode
 *	{
 *		char *	m_def;		Bit Relocation Definition
 *		a_uint	m_flag;		Bit Swapping Flag
 *		a_uint	m_dbits;	Destination Bit Mask
 *		a_uint	m_sbits;	Source Bit Mask
 *	};
 */
struct	mode	mode[1] = {
    {	&mode0[0],	0,	0x0000FFFF,	0x0000FFFF	}
};

/*
 * Array of Pointers to mode Structures
 */
struct	mode	*modep[16] = {
	&mode[0],	NULL,		NULL,		NULL,
	NULL,		NULL,		NULL,		NULL,
	NULL,		NULL,		NULL,		NULL,
	NULL,		NULL,		NULL,		NULL
};

/*
 * Mnemonic Structure
 */
struct	mne	mne[] = {

    /* Hash     Mnemonic    Subtype  Flags  Value       */
    /* link                                             */

	/* machine */

    {	NULL,	"CSEG",		S_ATYP,		0,	A_CSEG|A_1BYTE	},
    {	NULL,	"DSEG",		S_ATYP,		0,	A_DSEG|A_1BYTE	},

	/* system */

    {	NULL,	"BANK",		S_ATYP,		0,	A_BNK	},
    {	NULL,	"CON",		S_ATYP,		0,	A_CON	},
    {	NULL,	"OVR",		S_ATYP,		0,	A_OVR	},
    {	NULL,	"REL",		S_ATYP,		0,	A_REL	},
    {	NULL,	"ABS",		S_ATYP,		0,	A_ABS	},
    {	NULL,	"NOPAG",	S_ATYP,		0,	A_NOPAG	},
    {	NULL,	"PAG",		S_ATYP,		0,	A_PAG	},

    {	NULL,	"BASE",		S_BTYP,		0,	B_BASE	},
    {	NULL,	"SIZE",		S_BTYP,		0,	B_SIZE	},
    {	NULL,	"FSFX",		S_BTYP,		0,	B_FSFX	},
    {	NULL,	"MAP",		S_BTYP,		0,	B_MAP	},

    {	NULL,	".page",	S_PAGE,		0,	0	},
    {	NULL,	".title",	S_HEADER,	0,	O_TITLE	},
    {	NULL,	".sbttl",	S_HEADER,	0,	O_SBTTL	},
    {	NULL,	".module",	S_MODUL,	0,	0	},
    {	NULL,	".include",	S_INCL,		0,	0	},
    {	NULL,	".area",	S_AREA,		0,	0	},
    {	NULL,	".bank",	S_BANK,		0,	0	},
    {	NULL,	".org",		S_ORG,		0,	0	},
    {	NULL,	".radix",	S_RADIX,	0,	0	},
    {	NULL,	".globl",	S_GLOBL,	0,	0	},
    {	NULL,	".local",	S_LOCAL,	0,	0	},
    {	NULL,	".if",		S_CONDITIONAL,	0,	O_IF	},
    {	NULL,	".iff",		S_CONDITIONAL,	0,	O_IFF	},
    {	NULL,	".ift",		S_CONDITIONAL,	0,	O_IFT	},
    {	NULL,	".iftf",	S_CONDITIONAL,	0,	O_IFTF	},
    {	NULL,	".ifdef",	S_CONDITIONAL,	0,	O_IFDEF	},
    {	NULL,	".ifndef",	S_CONDITIONAL,	0,	O_IFNDEF},
    {	NULL,	".ifgt",	S_CONDITIONAL,	0,	O_IFGT	},
    {	NULL,	".iflt",	S_CONDITIONAL,	0,	O_IFLT	},
    {	NULL,	".ifge",	S_CONDITIONAL,	0,	O_IFGE	},
    {	NULL,	".ifle",	S_CONDITIONAL,	0,	O_IFLE	},
    {	NULL,	".ifeq",	S_CONDITIONAL,	0,	O_IFEQ	},
    {	NULL,	".ifne",	S_CONDITIONAL,	0,	O_IFNE	},
    {	NULL,	".ifb",		S_CONDITIONAL,	0,	O_IFB	},
    {	NULL,	".ifnb",	S_CONDITIONAL,	0,	O_IFNB	},
    {	NULL,	".ifidn",	S_CONDITIONAL,	0,	O_IFIDN	},
    {	NULL,	".ifdif",	S_CONDITIONAL,	0,	O_IFDIF	},
    {	NULL,	".iif",		S_CONDITIONAL,	0,	O_IIF	},
    {	NULL,	".iiff",	S_CONDITIONAL,	0,	O_IIFF	},
    {	NULL,	".iift",	S_CONDITIONAL,	0,	O_IIFT	},
    {	NULL,	".iiftf",	S_CONDITIONAL,	0,	O_IIFTF	},
    {	NULL,	".iifdef",	S_CONDITIONAL,	0,	O_IIFDEF},
    {	NULL,	".iifndef",	S_CONDITIONAL,	0,	O_IIFNDEF},
    {	NULL,	".iifgt",	S_CONDITIONAL,	0,	O_IIFGT	},
    {	NULL,	".iiflt",	S_CONDITIONAL,	0,	O_IIFLT	},
    {	NULL,	".iifge",	S_CONDITIONAL,	0,	O_IIFGE	},
    {	NULL,	".iifle",	S_CONDITIONAL,	0,	O_IIFLE	},
    {	NULL,	".iifeq",	S_CONDITIONAL,	0,	O_IIFEQ	},
    {	NULL,	".iifne",	S_CONDITIONAL,	0,	O_IIFNE	},
    {	NULL,	".iifb",	S_CONDITIONAL,	0,	O_IIFB	},
    {	NULL,	".iifnb",	S_CONDITIONAL,	0,	O_IIFNB	},
    {	NULL,	".iifidn",	S_CONDITIONAL,	0,	O_IIFIDN},
    {	NULL,	".iifdif",	S_CONDITIONAL,	0,	O_IIFDIF},
    {	NULL,	".else",	S_CONDITIONAL,	0,	O_ELSE	},
    {	NULL,	".endif",	S_CONDITIONAL,	0,	O_ENDIF	},
    {	NULL,	".list",	S_LISTING,	0,	O_LIST	},
    {	NULL,	".nlist",	S_LISTING,	0,	O_NLIST	},
    {	NULL,	".equ",		S_EQU,		0,	O_EQU	},
    {	NULL,	".gblequ",	S_EQU,		0,	O_GBLEQU},
    {	NULL,	".lclequ",	S_EQU,		0,	O_LCLEQU},
    {	NULL,	".byte",	S_DATA,		0,	O_1BYTE	},
    {	NULL,	".db",		S_DATA,		0,	O_1BYTE	},
    {	NULL,	".fcb",		S_DATA,		0,	O_1BYTE	},
    {	NULL,	".word",	S_DATA,		0,	O_2BYTE	},
    {	NULL,	".dw",		S_DATA,		0,	O_2BYTE	},
    {	NULL,	".fdb",		S_DATA,		0,	O_2BYTE	},
/*    {	NULL,	".3byte",	S_DATA,		0,	O_3BYTE	},	*/
/*    {	NULL,	".triple",	S_DATA,		0,	O_3BYTE	},	*/
/*    {	NULL,	".4byte",	S_DATA,		0,	O_4BYTE	},	*/
/*    {	NULL,	".quad",	S_DATA,		0,	O_4BYTE	},	*/
    {	NULL,	".blkb",	S_BLK,		0,	O_1BYTE	},
    {	NULL,	".ds",		S_BLK,		0,	O_1BYTE	},
    {	NULL,	".rmb",		S_BLK,		0,	O_1BYTE	},
    {	NULL,	".rs",		S_BLK,		0,	O_1BYTE	},
    {	NULL,	".blkw",	S_BLK,		0,	O_2BYTE	},
/*    {	NULL,	".blk3",	S_BLK,		0,	O_3BYTE	},	*/
/*    {	NULL,	".blk4",	S_BLK,		0,	O_4BYTE	},	*/
    {	NULL,	".ascii",	S_ASCIX,	0,	O_ASCII	},
    {	NULL,	".ascis",	S_ASCIX,	0,	O_ASCIS	},
    {	NULL,	".asciz",	S_ASCIX,	0,	O_ASCIZ	},
    {	NULL,	".str",		S_ASCIX,	0,	O_ASCII	},
    {	NULL,	".strs",	S_ASCIX,	0,	O_ASCIS	},
    {	NULL,	".strz",	S_ASCIX,	0,	O_ASCIZ	},
    {	NULL,	".fcc",		S_ASCIX,	0,	O_ASCII	},
    {	NULL,	".define",	S_DEFINE,	0,	O_DEF	},
    {	NULL,	".undefine",	S_DEFINE,	0,	O_UNDEF	},
    {	NULL,	".even",	S_BOUNDARY,	0,	O_EVEN	},
    {	NULL,	".odd",		S_BOUNDARY,	0,	O_ODD	},
    {	NULL,	".bndry",	S_BOUNDARY,	0,	O_BNDRY	},
    {	NULL,	".msg"	,	S_MSG,		0,	0	},
    {	NULL,	".assume",	S_ERROR,	0,	O_ASSUME},
    {	NULL,	".error",	S_ERROR,	0,	O_ERROR	},
/*    {	NULL,	".msb",		S_MSB,		0,	0	},	*/
/*    {	NULL,	".lohi",	S_MSB,		0,	O_LOHI	},	*/
/*    {	NULL,	".hilo",	S_MSB,		0,	O_HILO	},	*/
/*    {	NULL,	".8bit",	S_BITS,		0,	O_1BYTE	},	*/
/*    {	NULL,	".16bit",	S_BITS,		0,	O_2BYTE	},	*/
/*    {	NULL,	".24bit",	S_BITS,		0,	O_3BYTE	},	*/
/*    {	NULL,	".32bit",	S_BITS,		0,	O_4BYTE	},	*/
    {	NULL,	".end",		S_END,		0,	0	},

	/* Macro Processor */

    {	NULL,	".macro",	S_MACRO,	0,	O_MACRO	},
    {	NULL,	".endm",	S_MACRO,	0,	O_ENDM	},
    {	NULL,	".mexit",	S_MACRO,	0,	O_MEXIT	},

    {	NULL,	".narg",	S_MACRO,	0,	O_NARG	},
    {	NULL,	".nchr",	S_MACRO,	0,	O_NCHR	},
    {	NULL,	".ntyp",	S_MACRO,	0,	O_NTYP	},

    {	NULL,	".irp",		S_MACRO,	0,	O_IRP	},
    {	NULL,	".irpc",	S_MACRO,	0,	O_IRPC	},
    {	NULL,	".rept",	S_MACRO,	0,	O_REPT	},

    {	NULL,	".nval",	S_MACRO,	0,	O_NVAL	},

    {	NULL,	".mdelete",	S_MACRO,	0,	O_MDEL	},

	/* Machines */

    {	NULL,	".upd78310",    S_CPU,		0,	X_UPD78310	},
    {	NULL,	".upd78310a",	S_CPU,		0,	X_UPD78310A	},
    {	NULL,	".upd78320",	S_CPU,		0,	X_UPD78320	},
    {   NULL,   ".upd78328",    S_CPU,      0,  X_UPD78328  },
    {   NULL,   ".upd78330",    S_CPU,      0,  X_UPD78330  },
    {   NULL,   ".upd78350",    S_CPU,      0,  X_UPD78350  },
    {   NULL,   ".upd78356",    S_CPU,      0,  X_UPD78356  },
    {   NULL,   ".upd78362a",   S_CPU,      0,  X_UPD78362A },
    {   NULL,   ".upd78372",    S_CPU,      0,  X_UPD78372  },

	/* UPD78310 */

    /* Data transfer */

    {   NULL,   "mov",      S_MOV,      0, 0x00     },
    {   NULL,   "xch",      S_XCH,      0, 0x00     },
    {   NULL,   "movw",     S_MOVW,     0, 0x00     },
    {   NULL,   "xchw",     S_XCHW,     0, 0x00     },

    /* 8-bit Operations */

    {   NULL,   "add",      S_ADD,      0, 0x00     },
    {   NULL,   "sddc",     S_ADDC,     0, 0x00     },
    {   NULL,   "sub",      S_SUB,      0, 0x00     },
    {   NULL,   "subc",     S_SUBC,     0, 0x00     },
    {   NULL,   "and",      S_AND,      0, 0x00     },
    {   NULL,   "or",       S_OR,       0, 0x00     },
    {   NULL,   "xor",      S_XOR,      0, 0x00     },
    {   NULL,   "cmp",      S_CMP,      0, 0x00     },

    /* 16-bit Operations */

    {   NULL,   "addw",     S_ADDW,     0, 0x00     },
    {   NULL,   "subw",     S_SUBW,     0, 0x00     },
    {   NULL,   "cmpw",     S_CMPW,     0, 0x00     },

    /* Mult/Div */

    {   NULL,   "multu",    S_MULTU,    0, 0x00     },
    {   NULL,   "divuw",    S_DIVUW,    0, 0x00     },
    {   NULL,   "muluw",    S_MULUW,    0, 0x00     },
    {   NULL,   "divux",    S_DIVUX,    0, 0x00     },

    /* Increment and decrement */

    {   NULL,   "inc",      S_INC,      0, 0x00     },
    {   NULL,   "dec",      S_DEC,      0, 0x00     },
    {   NULL,   "incw",     S_INCW,     0, 0x00     },
    {   NULL,   "decw",     S_DECW,     0, 0x00     },

    /* Shift and rotate */

    {   NULL,   "ror",      S_ROR,      0, 0x00     },
    {   NULL,   "rol",      S_ROL,      0, 0x00     },
    {   NULL,   "rorc",     S_RORC,     0, 0x00     },
    {   NULL,   "rolc",     S_ROLC,     0, 0x00     },
    {   NULL,   "shr",      S_SHR,      0, 0x00     },
    {   NULL,   "shl",      S_SHL,      0, 0x00     },
    {   NULL,   "shrw",     S_SHRW,     0, 0x00     },
    {   NULL,   "shlw",     S_SHLW,     0, 0x00     },
    {   NULL,   "ror4",     S_ROR4,     0, 0x00     },
    {   NULL,   "rol4",     S_ROL4,     0, 0x00     },

    /* BCD */

    {   NULL,   "adj4",     S_ADJ4,     0, 0x04     },

    /* Bit manipulation */

    {   NULL,   "mov1",     S_MOV1,     0, 0x00     },
    {   NULL,   "and1",     S_AND1,     0, 0x00     },
    {   NULL,   "or1",      S_OR1,      0, 0x00     },
    {   NULL,   "xor1",     S_XOR1,     0, 0x00     },
    {   NULL,   "set1",     S_SET1,     0, 0x00     },
    {   NULL,   "clr1",     S_CLR1,     0, 0x00     },
    {   NULL,   "not1",     S_NOT1,     0, 0x00     },

    /* Call and return */

    {   NULL,   "call",     S_CALL,     0, 0x00     },
    {   NULL,   "callf",    S_CALLF,    0, 0x00     },
    {   NULL,   "callt",    S_CALLT,    0, 0x00     },
    {   NULL,   "brk",      S_BRK,      0, 0x5E     },
    {   NULL,   "ret",      S_RET,      0, 0x56     },
    {   NULL,   "reti",     S_RETI,     0, 0x57     },

    /* Stack Operations */

    {   NULL,   "push",     S_PUSH,     0, 0x00     },
    {   NULL,   "pushu",    S_PUSHU,    0, 0x00     },
    {   NULL,   "pop",      S_POP,      0, 0x00     },
    {   NULL,   "popu",     S_POPU,     0, 0x00     },

    /* Branching */

    {   NULL,   "br",       S_BR,       0, 0x00     },
    {   NULL,   "bc",       S_BC,       0, 0x00     },
    {   NULL,   "bl",       S_BL,       0, 0x00     },
    {   NULL,   "bnc",      S_BNC,      0, 0x00     },
    {   NULL,   "bnl",      S_BNL,      0, 0x00     },
    {   NULL,   "bz",       S_BZ,       0, 0x00     },
    {   NULL,   "be",       S_BE,       0, 0x00     },
    {   NULL,   "bnz",      S_BNZ,      0, 0x00     },
    {   NULL,   "bne",      S_BNE,      0, 0x00     },
    {   NULL,   "bv",       S_BV,       0, 0x00     },
    {   NULL,   "bpe",      S_BPE,      0, 0x00     },
    {   NULL,   "bnv",      S_BNV,      0, 0x00     },
    {   NULL,   "bpo",      S_BPO,      0, 0x00     },
    {   NULL,   "bn",       S_BN,       0, 0x00     },
    {   NULL,   "bp",       S_BP,       0, 0x00     },
    {   NULL,   "bgt",      S_BGT,      0, 0x00     },
    {   NULL,   "bge",      S_BGE,      0, 0x00     },
    {   NULL,   "blt",      S_BLT,      0, 0x00     },
    {   NULL,   "ble",      S_BLE,      0, 0x00     },
    {   NULL,   "bh",       S_BH,       0, 0x00     },
    {   NULL,   "bnh",      S_BNH,      0, 0x00     },
    {   NULL,   "bt",       S_BT,       0, 0x00     },
    {   NULL,   "bf",       S_BF,       0, 0x00     },
    {   NULL,   "btclr",    S_BTCLR,    0, 0x00     },
    {   NULL,   "bfset",    S_BFSET,    0, 0x00     },
    {   NULL,   "dbnz",     S_DBNZ,     0, 0x00     },

    /* Context Switching */

    {   NULL,   "brkcs",    S_BRKCS,    0, 0x00     },
    {   NULL,   "retcs",    S_RETCS,    0, 0x00     },

    /* String Operations */

    {   NULL,   "movm",     S_MOVM,     0, 0x00     },
    {   NULL,   "movbk",    S_MOVBK,    0, 0x00     },
    {   NULL,   "xchm",     S_XCHM,     0, 0x00     },
    {   NULL,   "xchbk",    S_XCHBK,    0, 0x00     },
    {   NULL,   "cmpme",    S_CMPME,    0, 0x00     },
    {   NULL,   "cmpbke",   S_CMPBKE,   0, 0x00     },
    {   NULL,   "cmpmne",   S_CMPMNE,   0, 0x00     },
    {   NULL,   "cmpbkne",  S_CMPBKNE,  0, 0x00     },
    {   NULL,   "cmpmc",    S_CMPMC,    0, 0x00     },
    {   NULL,   "cmpbkc",   S_CMPBKC,   0, 0x00     },
    {   NULL,   "cmpmnc",   S_CMPMNC,   0, 0x00     },
    {   NULL,   "cmpbknc",  S_CMPBKNC,  0, 0x00     },

    /* CPU Control */

    {   NULL,   "swrs",     S_SWRS,     0, 0x00     },
    {   NULL,   "sel",      S_SEL,      0, 0x00     },
    {   NULL,   "nop",      S_NOP,      0, 0x00     },
    {   NULL,   "ei",       S_EI,       0, 0x4B     },
    {   NULL,   "di",       S_DI,       0, 0x4A     },

    /* UPD78310A */

    /* no new instruction types, just a couple of additional addressing modes */

    /* UPD78320 */
    /* UPD78328 */
    /* UPD78330 */

	/* Adds 16-bit AX<->mem movw, 16-bit AX<->mem xchgw
        sign extend, retb, retcsb, sfrp push/pop, port test,
        signed mult, and three instructions changed or re-encoded.
    */

    /* UPD78350 */

    /* Adds macw and table shift */

    /* UPD78356 */
    /* UPD78362A */
    /* UPD78372 */

    /* Adds signalling mac, correlation */

    /* ------------------------------------------------------------ */

    {   NULL,   "$$XXX$$",  S_END_OF_OPS,  S_EOL, 0x00 }
};

/****************************************************************************/

