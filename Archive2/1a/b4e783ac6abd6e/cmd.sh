= RCS file: /cvs/src/usr.bin/ssh/monitor_wrap.c,v retrieving revision 1.76 diff -u -p -u -r1.76 monitor_wrap.c --- monitor_wrap.c	17 May 2013 00:13:13 -0000	1.76 +++ monitor_wrap.c	6 Nov 2013 16:31:26 -0000 @@ -469,7 +469,7 @@ mm_newkeys_from_blob(u_char *blob, int b buffer_init(&b); buffer_append(&b, blob, blen); -	newkey = xmalloc(sizeof(*newkey)); +	newkey = xcalloc(1, sizeof(*newkey)); enc = &newkey->enc; mac = &newkey->mac; comp = &newkey->comp;