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

#ifndef _N78K3_H_
#define _N78K3_H_

/* CPU Types */

#define X_UPD78310      0
#define X_UPD78310A     1
#define	X_UPD78320      2
#define X_UPD78328      3
#define X_UPD78330      4
#define X_UPD78350      5
#define X_UPD78356      6
#define X_UPD78362A     7
#define X_UPD78372      8

/* Operand types */

#define S_CPU           255

#define S_DATA_MOVE     60
    #define S_MOV       60
    #define S_XCH       61
    #define S_MOVW      62
    #define S_XCHW      63

#define S_ARTHIMETIC    70
    #define S_ADD       70
    #define S_ADDC      71
    #define S_SUB       72
    #define S_SUBC      73
    #define S_AND       74
    #define S_OR        75
    #define S_XOR       76
    #define S_CMP       77
    #define S_ADDW      78
    #define S_SUBW      79
    #define S_CMPW      80
    #define S_MULTU     81
    #define S_DIVUW     82
    #define S_MULUW     83
    #define S_DIVUX     84
    #define S_INC       85
    #define S_DEC       86
    #define S_INCW      87
    #define S_DECW      88

#define S_SHIFT_ROTATE  90
    #define S_ROR       90
    #define S_ROL       91
    #define S_RORC      92
    #define S_ROLC      93
    #define S_SHR       94
    #define S_SHL       95
    #define S_SHRW      96
    #define S_SHLW      97
    #define S_ROR4      98
    #define S_ROL4      99

#define S_BCD_OPS       100
    #define S_ADJ4      100

#define BITWISE_OPS     110
    #define S_MOV1      110
    #define S_AND1      111
    #define S_OR1       112
    #define S_XOR1      113
    #define S_SET1      114
    #define S_CLR1      115
    #define S_NOT1      116

#define S_CALL_RTN      120
    #define S_CALL      120
    #define S_CALLF     121
    #define S_CALLT     122
    #define S_BRK       123
    #define S_RET       124
    #define S_RETI      125

#define S_STACK_OPS     130
    #define S_PUSH      130
    #define S_PUSHU     131
    #define S_POP       132
    #define S_POPU      133

#define S_BRANCHING     140
    #define S_BR        140
    #define S_BC        141
    #define S_BL        142
    #define S_BNC       143
    #define S_BNL       144
    #define S_BZ        145
    #define S_BE        146
    #define S_BNZ       147
    #define S_BNE       148
    #define S_BV        149
    #define S_BPE       150
    #define S_BNV       151
    #define S_BPO       152
    #define S_BN        153
    #define S_BP        154
    #define S_BGT       155
    #define S_BGE       156
    #define S_BLT       157
    #define S_BLE       158
    #define S_BH        159
    #define S_BNH       160
    #define S_BT        161
    #define S_BF        162
    #define S_BTCLR     163
    #define S_BFSET     164
    #define S_DBNZ      165

#define S_CONTEXT_SW    170
    #define S_BRKCS     170
    #define S_RETCS     171

#define S_BLOCK_OPS     180
    #define S_MOVM      180
    #define S_MOVBK     181
    #define S_XCHM      182
    #define S_XCHBK     183
    #define S_CMPME     184
    #define S_CMPBKE    185
    #define S_CMPMNE    186
    #define S_CMPBKNE   187
    #define S_CMPMC     188
    #define S_CMPBKC    189
    #define S_CMPMNC    190
    #define S_CMPBKNC   191

#define S_SYSTEM_OPS    200
    #define S_SWRS      200
    #define S_SEL       201
    #define S_NOP       202
    #define S_EI        203
    #define S_DI        204

#define S_END_OF_OPS    1000

/****************************************************************************/

#ifdef OTHERSYSTEM
extern VOID machine(struct mne *mp);
extern VOID minit(void);
#else
extern VOID machine();
extern VOID minit();
#endif

/****************************************************************************/
#endif
/****************************************************************************/


