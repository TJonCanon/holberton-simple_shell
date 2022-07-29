#ifndef MACRO_H
#define MACRO_H

/* startprintf - initialize va__arg list, create buff of size 2048 */
#define startprintf do {				\
		va_start(args, format);			\
		bigbuf = calloc(2048, sizeof(char));	\
	} while (0)

/* v_init - initialize varialbe from va_arg of specified type */
#define v_init(var, type) do {				\
		loc = _strlen(bigbuf);			\
		var = va_arg(args, type);		\
	} while (0)

/* writestrtobuf - write a string of variable legnth to buffer */
#define writestrtobuf(ptr) for (; *ptr ; bigbuf[loc] = *ptr,	\
					ptr++,			\
					loc++,			\
					len++)

/* writetwochars - write 2 chars to buffer */
#define writetwochars do {			\
		bigbuf[c] = *(format - 1);	\
		bigbuf[c + 1] = *format;	\
		c += 2;				\
	} while (0)

/* endprintf - write buffer to stdout, end va_arg, free buffer*/
#define endprintf do {			\
		write(1, bigbuf, c);	\
		va_end(args);		\
		free(bigbuf);		\
	} while (0)

/* ABS - calculate abs of a number */
#define ABS(x) ((x) * (((x) > 0) - ((x) < 0)))

#endif
