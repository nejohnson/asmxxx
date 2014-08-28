

#ifdef OTHERSYSTEM

   /* n78kmch.c */
extern VOID  machine(struct mne *mp);
extern VOID  minit(void);


#else


   /* n78kmch.c */
extern VOID  machine();
extern VOID minit();

#endif


