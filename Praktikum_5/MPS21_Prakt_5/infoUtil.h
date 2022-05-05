#ifndef INFOUTIL_H_INCLUDED
#define INFOUTIL_H_INCLUDED

#include <stdio.h>

/**
 * \def SWINFO
 * Macro: Output SW and compile info. Implements printf statement
 * @param proj project name as string
 * @param auth author as string
 * @author R. S. Mayer
 */
#define SWINFO(proj,auth) \
 printf( "This is project >%s<, author %s, compiled on %s %s\n", proj, auth, __DATE__, __TIME__ )

/**
 * \def MSG
 * Macro: output message with line info. Implements printf statement
 * @param cat message category as char like I, W, E, F as 'E' e.g.
 * @param msg human readabel message as string
 * @param proc name of procedure as string, e.g. "Main"
 * @author R. S. Mayer
 */
#define MSG(cat,msg,proc) \
 printf( "%c: %s (%s, l:%d)\n", cat, msg, proc, __LINE__ )

/**
 * \def MSG_F
 * Macro: output message with line info. Implements printf statement
 * @param cat message category as char like I, W, E, F as 'E' e.g.
 * @param msg human readabel message as string
 * @param proc name of procedure as string, e.g. "Main"
 * @author R. S. Mayer
 */
#define MSG_F(cat,msg,proc) \
 printf( "%c: %s (%s:%s, l:%d)\n", cat, msg, __FILE__, proc, __LINE__ )

/**
 * \def MSGF
 * Macro: output message with line info. Implements printf statement
 * Need definition of
 * @see _FILE_
 * @param cat message category as char like I, W, E, F as 'E' e.g.
 * @param msg human readabel message as string
 * @param proc name of procedure as string, e.g. "Main"
 * @author R. S. Mayer
 */
#define MSGF(cat,msg,proc) \
 printf( "%c: %s (%s:%s, l:%d)\n", cat, msg, _FILE_, proc, __LINE__ )


// don't add code behind this line
#endif // INFOUTIL_H_INCLUDED
