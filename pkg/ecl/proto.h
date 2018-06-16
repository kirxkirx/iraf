/* binop.c */
extern char *strint(register char *s, int side);
extern void binop(int opcode);
extern void binexp(int opcode);
/* bkg.c */
extern void bkg_init(char *bcs);
extern void bkg_spawn(char *cmd);
extern void bkg_wait(register int job);
extern void bkg_kill(int job);
extern void bkg_jobstatus(struct _iobuf *fp, int job);
extern int bkg_jobactive(int job);
extern void bkg_update(int pmsg);
extern int bkg_wfservice(int job);
extern void bkg_delfiles(int job);
extern void bkg_startup(char *bkgfile);
extern void bkg_abort(void);
extern char *wbkgfile(int jobno, char *cmd, char *fname);
extern void rbkgfile(char *bkgfile);
/* builtin.c */
extern void clbye(void);
extern void cllogout(void);
extern void clclbye(void);
extern void clcache(void);
extern void cl_locate(char *task_spec, int first_only);
extern void clwhich(void);
extern void clwhereis(void);
extern void clflprcache(void);
extern void flpr_task(char *task);
extern void clprcache(void);
extern void clgflush(void);
extern void clchdir(void);
extern void clback(void);
extern void clerror(void);
extern void clhelp(void);
extern void clallhelp(void);
extern void clhistory(void);
extern void dotrace(void);
extern void clehistory(void);
extern void clservice(void);
extern void clkeep(void);
extern void clkill(void);
extern void cleparam(void);
extern void cllparam(void);
extern void cldparam(void);
extern void clpack(void);
extern void clcurpack(void);
extern void clpkg(void);
extern void lapkg(void);
extern void clprint(void);
extern void clfprint(void);
extern void do_clprint(char *dest);
extern void clprintf(void);
extern void clscans(void);
extern void clscanf(void);
extern void clputlog(void);
extern void clset(void);
extern void clreset(void);
extern void clshow(void);
extern void clstty(void);
extern void cltask(int redef);
extern void clrtask(void);
extern void clntask(void);
extern void clforeign(void);
extern void clunlearn(void);
extern void clupdate(void);
extern void clhidetask(void);
extern void clwait(void);
extern void cljobs(void);
extern void clfunc(void);
extern void clbeep(void);
extern void cltime(void);
extern void clclear(void);
extern void clsleep(void);
extern void cledit(void);
extern void clallocate(void);
extern void cldeallocate(void);
extern void cldevstatus(void);
extern void clerrpsh(void);
extern void clerreset(void);
extern void clonerror(void);
extern void setbuiltins(register struct package *pkp);
extern void newbuiltin(struct package *pkp, char *lname, void (*fp)(void), int flags, char *ftprefix, int redef);
extern int mkarglist(register struct pfile *pfp, char *args, char *argp[]);
extern void pushfparams(register struct param *pp);
extern void pushbparams(struct param *pp);
extern void pushbpvals(struct param *pp);
extern int nargs(struct pfile *pfp);
extern void keep(register struct task *tp);
/* clprintf.c */
extern void u_eprintf(char *fmt, ...);
extern void oprintf(char *fmt, ...);
extern void tprintf(char *fmt, ...);
extern void prparamval(struct param *pp, struct _iobuf *fp);
extern void strsort(char *list[], int nstr);
extern int qstrcmp(char *a, char *b);
extern void strtable(struct _iobuf *fp, char *list[], int nstr, int first_col, int last_col, int maxch, int ncol);
/* clsystem.c */
extern void clsystem(char *cmd, struct _iobuf *taskout, struct _iobuf *taskerr);
/* compile.c */
extern int compile(int opcode, ...);
extern int comstr(register char *s, memel *loc);
extern char *comdstr(char *s);
extern void catdstr(char *es, char *ns);
/* debug.c */
extern void d_asmark(void);
extern void d_assemble(void);
extern void d_stack(register XINT locpc, int ss, int endpc);
extern int d_instr(struct _iobuf *fp, char *prefix, register XINT locpc);
extern void d_d(void);
extern void d_p(void);
extern void d_t(void);
extern void d_l(void);
extern void d_f(void);
extern void d_on(void);
extern void d_off(void);
extern void d_trace(int value);
extern void e_dumpop(void);
extern void d_fmtmsg(struct _iobuf *fp, char *prefix, char *message, int width);
extern void d_prof(void);
/* decl.c */
extern int getlimits(char *pname, int n, int *i1, int *i2);
extern int get_dim(char *pname);
extern int maketype(int type, int list);
extern void do_arrayinit(struct param *pp, int nval, int nindex);
extern void do_scalarinit(struct param *pp, int inited);
extern int scanftype(struct param *pp, struct operand *o);
extern int c_scanmode(struct param *pp, struct operand *o);
extern int scanlen(struct param *pp, struct operand *o);
extern int scanmin(struct param *pp, struct operand *o);
extern int scanenum(register struct param *pp, register struct operand *o);
extern int scanmax(struct param *pp, struct operand *o);
extern void proc_params(int npar);
extern struct param *initparam(struct operand *op, int isparam, int type, int list);
extern int procscript(struct _iobuf *fp);
extern int skip_to(struct _iobuf *fp, char *key);
extern void do_option(struct param *pp, struct operand *oo, struct operand *o);
/* edcap.c */
extern void edtinit(void);
extern void edtexit(void);
extern char *host_editor(char *editor);
extern void get_editor(char *editor);
extern int what_cmd(int first_char);
extern int cmd_match(char *cstring, int nchars);
extern void show_editorhelp(void);
/* eparam.c */
extern int epset(char *pset);
extern int e_makelist(struct pfile *pfileptr);
extern int e_testtop(int cur, int new);
extern void e_repaint(void);
extern void e_pheader(struct pfile *pfp, int cmdline, int maxcol);
extern void e_drawkey(void);
extern void e_encode_vstring(struct param *pp, char *outbuf);
extern void e_check_vals(char *string);
extern int e_undef(register char *s);
extern void e_rpterror(char *errstr);
extern void e_clrerror(void);
extern char *e_getfield(register char *ip, char *outstr, int maxch);
extern int e_psetok(char *pset);
extern void e_puterr(char *errmsg);
extern void e_ttyexit(void);
extern int e_moreflag(int topkey);
extern void e_ttyinit (void);
extern int e_scrollit(void);
extern int e_colon (void);
extern int editstring (char *string, int eparam);
extern int e_moveup(int eparam);
extern int e_movedown(int eparam);
extern char *e_tonextword(register char *ip);
extern char *e_toprevword(char *ip, char *string);
extern void e_ctrl(char *cap);
extern void e_goto(int col, int line);
extern void e_putline(char *stwing);
extern void e_clear(void);
extern void e_clrline(void);
extern void e_display(char *string, int sline, int scol);
extern void e_displayml(char *string, int sline, int scol, int ccol);
/* errs.c */
extern void cl_error(int errtype, char *diagstr, ...);
extern void erract_init(void);
/* exec.c */
extern void run(void);
extern void callnewtask(char *name);
extern void execnewtask(void);
extern void mk_startupmsg(struct task *tp, char *cmd, int maxch);
extern char *findexe(struct package *pkg, char *pkg_path);
extern void set_clio(register struct task *newtask);
extern struct param *ppfind(struct pfile *pfp, char *tn, char *pn, int pos, int abbrev);
extern void psetreload(struct pfile *main_pfp, struct param *psetp);
extern void iofinish(register struct task *tp);
extern void restor(struct task *tp);
extern void oneof(void);
extern void printcall(struct _iobuf *fp, struct task *tp);
extern void print_call_line(struct _iobuf *out, int line, char *fname, int flags);
extern void killtask(register struct task *tp);
/* globals.c */
/* gquery.c */
extern char *gquery(struct param *pp, char *string);
extern char *minmax(register struct param *pp);
extern char *enumin(register struct param *pp);
/* gram.c */
extern int yywrap(void);
extern void yyerror(char *s);
extern void rerun(void);
extern int crackident(char *s);
extern XINT addconst(char *s, int t);
extern void listparams(struct pfile *pfp);
extern void pretty_param(struct param *pp, struct _iobuf *fp);
extern void dumpparams(struct pfile *pfp);
extern void show_param(struct ltask *ltp, struct param *pp, struct _iobuf *fp);
extern void listhelp(struct package *pkp, int show_invis);
extern void listallhelp(int show_invis);
extern void breakout(char *full, char **pk, char **t, char **p, char **f);
extern int fieldcvt(register char *f);
extern int keyword(register char *tbl[], register char *s);
extern void intrfunc(char *fname, int nargs);
extern struct operand sexa(char *s);
extern void sexa_to_index(double r, int *i1, int *i2);
extern char *addpipe(void);
extern char *getpipe(void);
extern void delpipes(register int npipes);
extern char *pipefile(int pipecode);
extern void loopincr(void);
extern void loopdecr(void);
extern void setswitch(void);
extern int in_switch(void);
extern void caseset(memel *parg, int ncaseval);
extern struct label *setlabel(struct operand *name);
extern struct label *getlabel(struct operand *name);
extern void setigoto(int loc);
extern void unsetigoto(int loc);
extern int make_imloop(int i1, int i2);
extern int y_typedef(char *key);
extern void p_position(void);
/* history.c */
extern int yy_getc(struct _iobuf *fp);
extern void yy_startblock(int logflag);
extern char *curcmd(void);
extern int get_command(struct _iobuf *fp);
extern int process_history_directive(char *directive, char *new_command_block);
extern int search_history(char *directive, char *new_command_block);
extern int stredit(char *edit_directive, char *in_text, char *out_text);
extern int expand_history_macros(char *in_text, char *out_text);
extern int get_arglist(char *cmdblk, char *argp[]);
extern void put_history(char *command);
extern int get_history(int record, char *command, int maxch);
extern void fetch_history(char *recptr, char *command, int maxch);
extern char *find_history(int record);
extern void show_history(struct _iobuf *fp, int max_commands);
extern void pprompt(register char *string);
extern void get_prompt(register char *string);
extern void put_logfile(char *command);
extern int open_logfile(char *fname);
extern void close_logfile(char *fname);
extern void reset_logfile(void);
extern int edit_history_directive(char *args, char *new_cmd);
extern void print_command(register struct _iobuf *fp, char *command, char *marg1, char *marg2);
extern char *today(void);
extern int what_record(void);
extern void putlog(struct task *tp, char *usermsg);
/* lexicon.c */
extern int yylex(void);
extern int lexicon(void);
extern int lexinit(void);
/* lists.c */
extern struct operand readlist(struct param *pp);
extern void closelist(register struct param *pp);
/* main.c */
extern int cmain_(short *cmd);
extern void clexit(void);
extern void clshutdown(void);
extern char *memneed(int incr);
extern void onint(int *vex, int (**next_handler)(void));
extern void intr_disable(void);
extern void intr_enable(void);
extern void intr_reset(void);
extern void onerr(void);
extern void cl_amovi(int *ip, int *op, int len);
/* modes.c */
extern int effmode(struct param *pp);
extern int taskmode(register struct task *tp);
extern void query(struct param *pp);
extern char *nextstr(char **pbuf, struct _iobuf *fp);
extern char *nxtchr(char *p, struct _iobuf *fp);
extern void pquery(register struct param *pp, struct _iobuf *fp);
extern char *bkg_query(char *obuf, int maxch, register struct param *pp);
extern void service_bkgquery(int bkgno);
extern void get_bkgqfiles(int bkgno, int pid, char *bkg_query_file, char *query_response_file);
extern int inrange(register struct param *pp, register struct operand *op);
extern int range_check(struct param *pp);
extern void setclmodes(struct task *tp);
extern void parse_clmodes(struct param *pp, struct operand *newval);
extern int abbrev(void);
extern void poffset(int off);
/* opcodes.c */
extern void o_undefined(void);
extern void o_absargset(memel *argp);
extern void o_add(void);
extern void o_addassign(memel *argp);
extern void o_allappend(void);
extern void o_allredir(void);
extern void o_and(void);
extern void o_append(void);
extern void o_assign(memel *argp);
extern void o_biff(memel *argp);
extern void o_call(memel *argp);
extern void o_chsign(void);
extern void o_concat(void);
extern void o_div(void);
extern void o_doend(void);
extern void o_divassign(memel *argp);
extern void o_catassign(memel *argp);
extern void o_eq(void);
extern void o_exec(void);
extern void o_ge(void);
extern void o_dogoto(memel *argp);
extern void o_gt(void);
extern void o_indirabsset(memel *argp);
extern void o_indirposset(memel *argp);
extern void o_indxincr(memel *argp);
extern void o_inspect(memel *argp);
extern void o_intrinsic(memel *argp);
extern void o_le(void);
extern void o_lt(void);
extern void o_mul(void);
extern void o_mulassign(memel *argp);
extern void o_ne(void);
extern void o_not(void);
extern void o_or(void);
extern void o_osesc(memel *argp);
extern void o_posargset(memel *argp);
extern void o_dopow(void);
extern void o_doprint(void);
extern void o_immed(void);
extern void o_pushconst(memel *argp);
extern void o_pushindex(int *mode);
extern void o_pushparam(memel *argp);
extern void o_redir(void);
extern void o_redirin(void);
extern void o_gsredir(memel *argp);
extern void o_doaddpipe(memel *argp);
extern void o_dogetpipe(memel *argp);
extern void o_rmpipes(memel *argp);
extern void o_doreturn(void);
extern void o_doscan(void);
extern void o_doscanf(void);
extern void o_dofscan(void);
extern void o_dofscanf(void);
extern void o_sub(void);
extern void o_subassign(memel *argp);
extern void o_doswitch(int *jmpdelta);
extern void o_swoff(memel *argp);
extern void o_swon(memel *argp);
extern void o_fixlanguage(void);
/* operand.c */
extern void sprop(register char *outstr, register struct operand *op);
extern void spparval(char *outstr, struct param *pp);
extern void fprop(struct _iobuf *fp, struct operand *op);
extern void oprop(struct operand *op);
extern void prop(struct operand *op);
extern void opindir(void);
extern void opcast(int newtype);
extern struct operand makeop(char *str, int type);
/* param.c */
extern struct param *paramfind(struct pfile *pfp, char *pname, int pos, int exact);
extern void paramset(register struct param *pp, int field);
extern void validparamget(register struct param *pp, int field);
extern void paramget(register struct param *pp, int field);
extern void makemode(struct param *pp, char *s);
extern struct param *newparam(struct pfile *pfp);
extern struct param *paramsrch(char *pkname, char *ltname, char *pname);
extern int defpar(char *param_spec);
extern int defvar(char *envvar);
extern struct param *lookup_param(char *pkname, char *ltname, char *pname);
extern int printparam(struct param *pp, register struct _iobuf *fp);
extern void qputs(register char *str, register struct _iobuf *fp);
extern int pvaldefined(struct param *pp, char *s);
extern struct param *newfakeparam(struct pfile *pfp, char *name, int pos, int type, int string_len);
extern int getoffset(struct param *pp);
extern void offsetmode(int mode);
extern int size_array(struct param *pp);
/* pfiles.c */
extern struct pfile *newpfile(struct ltask *ltp);
extern void pfileunlink(register struct pfile *pfp);
extern struct pfile *pfilefind(register struct ltask *ltp);
extern struct pfile *pfilesrch(char *pfilepath);
extern struct pfile *pfileload(register struct ltask *ltp);
extern int pfilemerge(struct pfile *npf, char *opfile);
extern void pfileupdate(struct pfile *pfp);
extern struct pfile *pfileread(struct ltask *ltp, char *pfilename, int checkmode);
extern int pfilewrite(struct pfile *pfp, char *pfilename);
extern int pfileinit(struct ltask *ltp);
extern int is_pfilename(char *opstr);
extern void mkpfilename(char *buf, char *dir, char *pkname, char *ltname, char *extn);
extern long filetime(char *fname, char *timecode);
extern struct pfile *pfilecopy(register struct pfile *pfp);
extern void pfcopyback(struct pfile *pff);
extern struct param *addparam(struct pfile *pfp, char *buf, struct _iobuf *fp);
extern int ck_atoi(char *str, int *val);
extern char *nextfield(char **pp, struct _iobuf *fp);
extern char *makelower(register char *cp);
extern int scanmode(char *s);
extern int scantype(register char *s);
/* prcache.c */
extern int pr_connect(char *process, char *command, struct _iobuf **in, struct _iobuf **out, struct _iobuf *t_in, struct _iobuf *t_out, struct _iobuf *t_err, struct _iobuf *t_gr, struct _iobuf *t_im, struct _iobuf *t_pl, int timeit);
extern void pr_disconnect(int pid);
extern int pr_pconnect(char *process, struct _iobuf **in, struct _iobuf **out);
extern void pr_setcache(int new_szprcache);
extern int pr_cachetask(char *ltname);
extern void pr_lock(register int pid);
extern int pr_unlock(register int pid);
extern void pr_listcache(struct _iobuf *fp);
extern void pr_dumpcache(int pid, int break_locks);
extern void pr_prunecache(int pno);
extern int pr_getpno(void);
extern int pr_pnametopid(char *pname);
extern void pr_chdir(register int pid, char *newdir);
extern void pr_envset(register int pid, char *envvar, char *valuestr);
extern void pr_checkup(void);
extern void pr_initcache(void);
/* scan.c */
extern void cl_scan(int nargs, char *source);
extern void cl_scanf(char *format, int nargs, char *input);
extern int get_nscanval(void);
extern void lentst(char *buf);
/* stack.c */
extern void pushmem(memel v);
extern memel popmem(void);
extern void ppushmem(register memel p);
extern struct operand pushop(struct operand *op);
extern struct operand popop(void);
extern struct task *pushtask(void);
extern struct task *poptask(void);
/* task.c */
extern struct ltask *cmdsrch(char *pkname, char *ltname);
extern struct ltask *ltasksrch(char *pkname, char *ltname);
extern struct ltask *_ltasksrch(char *pkname, char *ltname, struct package **o_pkp);
extern struct package *pacfind(char *name);
extern int defpac(char *pkname);
extern struct ltask *ltaskfind(struct package *pkp, char *name, int enable_abbreviations);
extern int deftask(char *task_spec);
extern void taskunwind(void);
extern struct ltask *addltask(struct package *pkp, char *ptname, char *ltname, int redef);
extern struct ltask *newltask(register struct package *pkp, char *lname, char *pname, struct ltask *oldltp);
extern struct package *newpac(char *name, char *bin);
/* unop.c */
extern void unop(int opcode);
extern void unexp(int opcode);
