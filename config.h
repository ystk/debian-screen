/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.in by autoheader.  */
/* Copyright (c) 1993-2000
 *      Juergen Weigert (jnweiger@immd4.informatik.uni-erlangen.de)
 *      Michael Schroeder (mlschroe@immd4.informatik.uni-erlangen.de)
 * Copyright (c) 1987 Oliver Laumann
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (see the file COPYING); if not, see
 * http://www.gnu.org/licenses/, or contact Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 *
 ****************************************************************
 * $Id$ GNU
 */





/**********************************************************************
 *
 *	User Configuration Section
 */

/*
 * Maximum of simultaneously allowed windows per screen session.
 */
#ifndef MAXWIN
# define MAXWIN 100
#endif

/*
 * Define SOCKDIR to be the directory to contain the named sockets
 * screen creates. This should be in a common subdirectory, such as
 * /usr/local or /tmp. It makes things a little more secure if you
 * choose a directory which is not writable by everyone or where the
 * "sticky" bit is on, but this isn't required.
 * If SOCKDIR is not defined screen will put the named sockets in
 * the user's home directory. Notice that this can cause you problems
 * if some user's HOME directories are AFS- or NFS-mounted. Especially
 * AFS is unlikely to support named sockets.
 *
 * Screen will name the subdirectories "S-$USER" (e.g /tmp/S-davison).
 */
#define SOCKDIR "/run/screen"

/*
 * Define this if the SOCKDIR is not shared between hosts.
 */
#define SOCKDIR_IS_LOCAL_TO_HOST

/*
 * Screen can look for the environment variable $SYSSCREENRC and -if it
 * exists- load the file specified in that variable as global screenrc.
 * If you want to enable this feature, define ALLOW_SYSSCREENRC to one (1).
 * Otherwise ETCSCREENRC is always loaded.
 */
#define ALLOW_SYSSCREENRC 1

/*
 * Define CHECKLOGIN to force Screen users to enter their Unix password
 * in addition to the screen password.
 *
 * Define NOSYSLOG if yo do not have logging facilities. Currently
 * syslog() will be used to trace ``su'' commands only.
 */
#define CHECKLOGIN 1
/* #undef NOSYSLOG */


/* 
 * define PTYMODE if you do not like the default of 0622, which allows 
 * public write to your pty.
 * define PTYGROUP to some numerical group-id if you do not want the
 * tty to be in "your" group.
 * Note, screen is unable to change mode or group of the pty if it
 * is not installed with sufficient privilege. (e.g. set-uid-root)
 * define PTYROFS if the /dev/pty devices are mounted on a read-only 
 * filesystem so screen should not even attempt to set mode or group  
 * even if running as root (e.g. on TiVo).
 */
#define PTYMODE 0620
#define PTYGROUP 5
/* #undef PTYROFS */

/*
 * If screen is NOT installed set-uid root, screen can provide tty
 * security by exclusively locking the ptys.  While this keeps other
 * users from opening your ptys, it also keeps your own subprocesses
 * from being able to open /dev/tty.  Define LOCKPTY to add this
 * exclusive locking.
 */
/* #undef LOCKPTY */

/*
 * If you'd rather see the status line on the first line of your
 * terminal rather than the last, define TOPSTAT.
 */
/* #undef TOPSTAT */

/*
 * define DETACH can detach a session. An absolute 'must'.
 */
#define DETACH

/*
 * here come the erlangen extensions to screen:
 * define LOCK if you want to use a lock program for a screenlock.
 * define PASSWORD for secure reattach of your screen.
 * define COPY_PASTE to use the famous hacker's treasure zoo.
 * define POW_DETACH to have a detach_and_logout key (requires DETACH).
 * define REMOTE_DETACH (-d option) to move screen between terminals.
 * define AUTO_NUKE to enable Tim MacKenzies clear screen nuking
 * define PSEUDOS to allow window input/output filtering
 * define MULTI to allow multiple attaches.
 * define MULTIUSER to allow other users attach to your session
 *                  (if they are in the acl, of course)
 * define MAPKEYS to include input keyboard translation.
 * define FONT to support ISO2022/alternet charset support
 * define COLOR to include ansi color support. This may expose
 *        a bug in x11r6-color-xterm.
 * define DW_CHARS to include support for double-width character
 *        sets.
 * define ENCODINGS to include support for encodings like euc or big5.
 *        Needs FONT to work.
 * define UTF8 if you want support for UTF-8 encoding.
 *        Needs FONT and ENCODINGS to work.
 * define COLORS16 if you want 16 colors.
 *        Needs COLOR to work.
 * define BUILTIN_TELNET to add telnet support to screen.
 *        Syntax: screen //telnet host [port]
 * define RXVT_OSC if you want support for rxvts special
 *        change fgcolor/bgcolor/bgpicture sequences
 */
/* #undef SIMPLESCREEN */
#ifndef SIMPLESCREEN
# define LOCK
# define PASSWORD
# define COPY_PASTE
# define REMOTE_DETACH
# define POW_DETACH
# define AUTO_NUKE
# define PSEUDOS
# define MULTI
# define MULTIUSER
# define MAPKEYS
# define COLOR
# define FONT
# define DW_CHARS
# define ENCODINGS
# define UTF8
# define COLORS16
# define ZMODEM
# define BLANKER_PRG
#endif /* SIMPLESCREEN */

#define BUILTIN_TELNET 1
#define RXVT_OSC 1
#define COLORS256 1


/*
 * If you have a braille display you should define HAVE_BRAILLE.
 * The code inside #ifdef HAVE_BRAILLE was contributed by Hadi Bargi
 * Rangin (bargi@dots.physics.orst.edu).
 * WARNING: this is more or less unsupported code, it may be full of
 * bugs leading to security holes, enable at your own risk!
 */
/* #undef HAVE_BRAILLE */


/*
 * As error messages are mostly meaningless to the user, we
 * try to throw out phrases that are somewhat more familiar
 * to ...well, at least familiar to us NetHack players.
 */
#ifndef NONETHACK
# define NETHACK
#endif /* NONETHACK */

/*
 * If screen is installed with permissions to update /etc/utmp (such
 * as if it is installed set-uid root), define UTMPOK.
 */
#define UTMPOK

/* Set LOGINDEFAULT to one (1)
 * if you want entries added to /etc/utmp by default, else set it to
 * zero (0).
 * LOGINDEFAULT will be one (1) whenever LOGOUTOK is undefined!
 */
#define LOGINDEFAULT	1

/* Set LOGOUTOK to one (1)
 * if you want the user to be able to log her/his windows out.
 * (Meaning: They are there, but not visible in /etc/utmp).
 * Disabling this feature only makes sense if you have a secure /etc/utmp
 * database. 
 * Negative examples: suns usually have a world writable utmp file, 
 * xterm will run perfectly without s-bit.
 *
 * If LOGOUTOK is undefined and UTMPOK is defined, all windows are
 * initially and permanently logged in.
 *
 * Set CAREFULUTMP to one (1) if you want that users have at least one
 * window per screen session logged in.
 */
#define LOGOUTOK 1
/* #undef CAREFULUTMP */


/*
 * If UTMPOK is defined and your system (incorrectly) counts logins by
 * counting non-null entries in /etc/utmp (instead of counting non-null
 * entries with no hostname that are not on a pseudo tty), define USRLIMIT
 * to have screen put an upper-limit on the number of entries to write
 * into /etc/utmp.  This helps to keep you from exceeding a limited-user
 * license.
 */
/* #undef USRLIMIT */

/*
 * both must be defined if you want to favor tcsendbreak over
 * other calls to generate a break condition on serial lines.
 * (Do not bother, if you are not using plain tty windows.)
 */
#define POSIX_HAS_A_GOOD_TCSENDBREAK
#define SUNOS4_AND_WE_TRUST_TCSENDBREAK

/*
 * to lower the interrupt load on the host machine, you may want to
 * adjust the VMIN and VTIME settings used for plain tty windows.
 * See the termio(4) manual page (Non-Canonical Mode Input Processing)
 * for details.
 * if undefined, VMIN=1, VTIME=0 is used as a default - this gives you
 * best user responsiveness, but highest interrupt frequency.
 * (Do not bother, if you are not using plain tty windows.)
 */
#define TTYVMIN 100
#define TTYVTIME 2

/*
 * looks like the above values are ignored by setting FNDELAY.
 * This is default for all pty/ttys, you may disable it for
 * ttys here. After playing with it for a while, one may find out
 * that this feature may cause screen to lock up.
 */
#ifdef bsdi
# define TTY_DISABLE_FNBLOCK /* select barfs without it ... */
#endif


/*
 * Some terminals, e.g. Wyse 120, use a bitfield to select attributes.
 * This doesn't work with the standard so/ul/m? terminal entries,
 * because they will cancel each other out. 
 * On TERMINFO machines, "sa" (sgr) may work. If you want screen
 * to switch attributes only with sgr, define USE_SGR.
 * This is *not* recomended, do this only if you must.
 */
/* #undef USE_SGR */


/*
 * Define USE_LOCALE if you want screen to use the locale names
 * for the name of the month and day of the week.
 */
#define USE_LOCALE

/*
 * Define USE_PAM if your system supports PAM (Pluggable Authentication
 * Modules) and you want screen to use it instead of calling crypt().
 * (You may also need to add -lpam to LIBS in the Makefile.)
 */
#define USE_PAM 1

/*
 * Define CHECK_SCREEN_W if you want screen to set TERM to screen-w
 * if the terminal width is greater than 131 columns. No longer needed
 * on modern systems which use $COLUMNS or the tty settings instead.
 */
/* #undef CHECK_SCREEN_W */

/**********************************************************************
 *
 *	End of User Configuration Section
 *
 *      Rest of this file is modified by 'configure'
 *      Change at your own risk!
 *
 */

/*
 * Some defines to identify special unix variants
 */
#ifndef SVR4
#define SVR4 1
#endif

/* #ifndef __osf__ */
#ifndef MIPS
/* #undef MIPS */
#endif
/* #endif */

#ifndef OSX
/* #undef OSX */
#endif

#ifndef ISC
/* #undef ISC */
#endif

#ifndef sysV68
/* #undef sysV68 */
#endif

#ifndef _POSIX_SOURCE
/* #undef _POSIX_SOURCE */
#endif

/*
 * Define POSIX if your system supports IEEE Std 1003.1-1988 (POSIX).
 */
#define POSIX 1

/*
 * Define BSDJOBS if you have BSD-style job control (both process
 * groups and a tty that deals correctly with them).
 */
#define BSDJOBS 1

/*
 * Define TERMIO if you have struct termio instead of struct sgttyb.
 * This is usually the case for SVID systems, where BSD uses sgttyb.
 * POSIX systems should define this anyway, even though they use
 * struct termios.
 */
#define TERMIO 1

/*
 * Define CYTERMIO if you have cyrillic termio modes.
 */
/* #undef CYTERMIO */

/*
 * Define TERMINFO if your machine emulates the termcap routines
 * with the terminfo database.
 * Thus the .screenrc file is parsed for
 * the command 'terminfo' and not 'termcap'.
 */
#define TERMINFO 1

/*
 * If your library does not define ospeed, define this.
 */
/* #undef NEED_OSPEED */

/*
 * Define SYSV if your machine is SYSV complient (Sys V, HPUX, A/UX)
 */
#ifndef SYSV
/* #undef SYSV */
#endif

/*
 * Define SIGVOID if your signal handlers return void.  On older
 * systems, signal returns int, but on newer ones, it returns void.
 */
#define SIGVOID 1

/*
 * Define USESIGSET if you have sigset for BSD 4.1 reliable signals.
 */
/* #undef USESIGSET */

/*
 * Define SYSVSIGS if signal handlers must be reinstalled after
 * they have been called.
 */
/* #undef SYSVSIGS */

/*
 * Define BSDWAIT if your system defines a 'union wait' in <sys/wait.h>
 *
 * Only allow BSDWAIT i.e. wait3 on nonposix systems, since
 * posix implies wait(3) and waitpid(3). vdlinden@fwi.uva.nl
 * 
 */
#ifndef POSIX
#define BSDWAIT 1
#endif

/*
 * On RISCOS we prefer wait2() over wait3(). rouilj@sni-usa.com 
 */
#ifdef BSDWAIT
/* #undef USE_WAIT2 */
#endif

/*
 * If your system has getutent(), pututline(), etc. to write to the
 * utmp file, define GETUTENT.
 */
#define GETUTENT 1

/*
 * Define UTHOST if the utmp file has a host field.
 */
#define UTHOST 1

/*
 * Define if you have the utempter utmp helper program
 */
#define HAVE_UTEMPTER 1

/*
 * If ttyslot() breaks getlogin() by returning indexes to utmp entries
 * of type DEAD_PROCESS, then our getlogin() replacement should be
 * selected by defining BUGGYGETLOGIN.
 */
#define BUGGYGETLOGIN 1

/*
 * If your system has the calls setreuid() and setregid(),
 * define HAVE_SETREUID. Otherwise screen will use a forked process to
 * safely create output files without retaining any special privileges.
 */
#define HAVE_SETRESUID 1
#define HAVE_SETREUID 1

/*
 * If your system supports BSD4.4's seteuid() and setegid(), define
 * HAVE_SETEUID.
 */
/* #undef HAVE_SETEUID */

/*
 * execvpe is now defined in some systems.
 */
#define HAVE_EXECVPE 1

/*
 * If you want the "time" command to display the current load average
 * define LOADAV. Maybe you must install screen with the needed
 * privileges to read /dev/kmem.
 * Note that NLIST_ stuff is only checked, when getloadavg() is not available.
 */
#define LOADAV 1

#define LOADAV_NUM 3
#define LOADAV_TYPE double
#define LOADAV_SCALE 1
#define LOADAV_GETLOADAVG 1
/* #undef LOADAV_UNIX */
/* #undef LOADAV_AVENRUN */
/* #undef LOADAV_USE_NLIST64 */

/* #undef NLIST_DECLARED */
/* #undef NLIST_STRUCT */
/* #undef NLIST_NAME_UNION */

/*
 * If your system has the new format /etc/ttys (like 4.3 BSD) and the
 * getttyent(3) library functions, define GETTTYENT.
 */
#define GETTTYENT 1

/*
 * Define USEBCOPY if the bcopy/memcpy from your system's C library
 * supports the overlapping of source and destination blocks.  When
 * undefined, screen uses its own (probably slower) version of bcopy().
 * 
 * SYSV machines may have a working memcpy() -- Oh, this is 
 * quite unlikely. Tell me if you see one.
 * "But then, memmove() should work, if at all available" he thought...
 * Boing, never say "works everywhere" unless you checked SCO UNIX.
 * Their memove fails the test in the configure script. Sigh. (Juergen)
 */
#define USEBCOPY 1
/* #undef USEMEMCPY */
#define USEMEMMOVE 1

/*
 * If your system has vsprintf() and requires the use of the macros in
 * "varargs.h" to use functions with variable arguments,
 * define USEVARARGS.
 */
#define USEVARARGS 1

/*
 * If the select return value doesn't treat a descriptor that is
 * usable for reading and writing as two hits, define SELECT_BROKEN.
 */
/* #undef SELECT_BROKEN */

/*
 * Define this if your system supports named pipes.
 */
/* #undef NAMEDPIPE */

/*
 * Define this if your system exits select() immediatly if a pipe is
 * opened read-only and no writer has opened it.
 */
/* #undef BROKEN_PIPE */

/*
 * Define this if the unix-domain socket implementation doesn't
 * create a socket in the filesystem.
 */
/* #undef SOCK_NOT_IN_FS */

/*
 * If your system has setenv() and unsetenv() define USESETENV
 */
#define USESETENV 1

/*
 * If setenv() takes 3 arguments define HAVE_SETENV_3
 */
#define HAVE_SETENV_3 1

/*
 * If setenv() takes 2 arguments define HAVE_SETENV_2
 */
/* #undef HAVE_SETENV_2 */

/*
 * If your system does not come with a setenv()/putenv()/getenv()
 * functions, you may bring in our own code by defining NEEDPUTENV.
 */
/* #undef NEEDPUTENV */

/*
 * If the passwords are stored in a shadow file and you want the
 * builtin lock to work properly, define SHADOWPW.
 */
#define SHADOWPW 1

/*
 * define HAVE_NL_LANGINFO if your system has the nl_langinfo() call
 * and <langinfo.h> defines CODESET.
 */
#define HAVE_NL_LANGINFO 1

/*
 * Newer versions of Solaris include fdwalk, which can greatly improve
 * the startup time of screen; otherwise screen spends a lot of time
 * closing file descriptors.
 */
/* #undef HAVE_FDWALK */

/*
 * define HAVE_DEV_PTC if you have a /dev/ptc character special
 * device.
 */
/* #undef HAVE_DEV_PTC */

/*
 * define HAVE_SVR4_PTYS if you have a /dev/ptmx character special
 * device and support the ptsname(), grantpt(), unlockpt() functions.
 */
#define HAVE_SVR4_PTYS 1

/* 
 * define PTYRANGE0 and or PTYRANGE1 if you want to adapt screen
 * to unusual environments. E.g. For SunOs the defaults are "qpr" and 
 * "0123456789abcdef". For SunOs 4.1.2 
 * #define PTYRANGE0 "pqrstuvwxyzPQRST" 
 * is recommended by Dan Jacobson.
 */
/* #undef PTYRANGE0 */
/* #undef PTYRANGE1 */


/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the `fchmod' function. */
#define HAVE_FCHMOD 1

/* Define to 1 if you have the `fchown' function. */
#define HAVE_FCHOWN 1

/* Define to 1 if you have the `getcwd' function. */
#define HAVE_GETCWD 1

/* Define to 1 if you have the `getpt' function. */
#define HAVE_GETPT 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you support file names longer than 14 characters. */
#define HAVE_LONG_FILE_NAMES 1

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the `openpty' function. */
/* #undef HAVE_OPENPTY */

/* Define to 1 if you have the `rename' function. */
#define HAVE_RENAME 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the `strftime' function. */
#define HAVE_STRFTIME 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <stropts.h> header file. */
#define HAVE_STROPTS_H 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `utimes' function. */
#define HAVE_UTIMES 1

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* Define to 1 if you have the `_exit' function. */
#define HAVE__EXIT 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */