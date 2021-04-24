<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );
#define( 'WP_HOME', 'http://MINIKUBE-IP:5050' );
#define( 'WP_SITEURL', 'http://MINIKUBE-IP:5050' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'K/K.Jp,O8fmF. r)b$_!3iv/Y3(O_=q$<DZDj1x*6|0F8,{IBRyDrg#<|H#o2{_6' );
define( 'SECURE_AUTH_KEY',  'yc-^^6v4|J-vd6cA+,R51M&cv_G^gn]Y!sTT4f&%PY@|El+MuIJJh<g}(+Ns<$+|' );
define( 'LOGGED_IN_KEY',    ',Y aP?4^[vlR+US{7sDbtFP(oKjls[ FaMLc)haO/`)`/7#j0BCJ<QN~94 )+:!-' );
define( 'NONCE_KEY',        '~=UMZ6NA,B`3~HURhe7@N&tN+]WK-(.~M|,+(VTGR|n&2lj-R5JY!ZT:dlA573U;' );
define( 'AUTH_SALT',        'gRivtt=3Y/F_AZ8Sh-y9Mqi|f#NI4fWg%XPf}8jN=F2sZ?*H=!gP%rnEloSg3_U`' );
define( 'SECURE_AUTH_SALT', 'Fm@]|b->(Q/zTdZQeo|*FHwr0P8W/q!TY7Ecai|c+V-%ZWQL+SzYFsL*]2h`g~#4' );
define( 'LOGGED_IN_SALT',   '0i|R7nZIw,E86a0Cs$@KXP!Yx5u&/B31]]3&V3t@Wq|jIi$9yeE7Usq)=PR-cJ [' );
define( 'NONCE_SALT',       'Uv|&Mj/`;i{-)<pB23k4fMJ(6|lh*Vh:TLvW|v-_Io$/jp@+PZ=rZoJ{&f,#2_n~' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define('WP_ALLOW_REPAIR', true);
define( 'WP_DEBUG', true);
define( 'WP_DEBUG_LOG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
