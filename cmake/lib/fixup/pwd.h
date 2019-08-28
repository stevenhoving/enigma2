#pragma once

#include <sys/types.h>

using uid_t = int;
using gid_t = int;

struct passwd {
	char	*pw_name;		/* user name */
	char	*pw_passwd;		/* encrypted password */
	uid_t	pw_uid;			/* user uid */
	gid_t	pw_gid;			/* user gid */
	time_t	pw_change;		/* password change time */
	char	*pw_class;		/* user access class */
	char	*pw_gecos;		/* Honeywell login info */
	char	*pw_dir;		/* home directory */
	char	*pw_shell;		/* default shell */
	time_t	pw_expire;		/* account expiration */
};

static struct passwd	*getpwuid(uid_t)
{
    return nullptr;
}

static struct passwd	*getpwnam(const char *)
{
    return nullptr;
}

static struct passwd	*getpwuid_shadow(uid_t)
{
    return nullptr;
}

static struct passwd	*getpwnam_shadow(const char *)
{
    return nullptr;
}

static int		getpwnam_r(const char *, struct passwd *, char *, size_t,
    struct passwd **)
{
    return 0;
}

static int		getpwuid_r(uid_t, struct passwd *, char *, size_t,
    struct passwd **)
{
    return 0;
}
