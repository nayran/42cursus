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
define( 'DB_NAME', 'wpbase' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', 'nasimon' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

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
define( 'AUTH_KEY',         '{jIa(b=)B*H#+.JjcnVm.#/ACS7kG(mw<,AHO@uBFR|?Y#42ml&FVg+-x|Z^vAk&' );
define( 'SECURE_AUTH_KEY',  'zgU]??z)ys!tm^_pYT&%[>nx!V;6&^4)8Kq9$NMP92qM]7R(s2jwobEl7gKp6iOK' );
define( 'LOGGED_IN_KEY',    '`o-,l:H^hWy6[t!)BjQR8$$wN^dBmXvt%JVXl@&zu8Q=KNGkzT.xWK ^t#|;stWp' );
define( 'NONCE_KEY',        '=^+=q#oDTYua2CB)uA&k<Z4(X7<~=P=!~QnO0SFgxsS(T(6w#AczK(^G&lciXR/a' );
define( 'AUTH_SALT',        'Br;|N-+RVxhOSDv9hYDc%Z9_^$6TL=(`TvcS);F>%FREM37vo,gAoIdR>F_a[RJ-' );
define( 'SECURE_AUTH_SALT', '}7X{V9l2LF%u<um)Hdg!YarL7{OXv_b4rBjh38NoRf(:ga+XwUfMAvA*8Qf; F}m' );
define( 'LOGGED_IN_SALT',   '5)8}CG,%U~bb%$8Qa[FotqKcbKv);S,.xs0&&L_$9s$K>=^?OL$RCR:| 7J4rizy' );
define( 'NONCE_SALT',       '7K+fNy4C p:u N K[]`cY#MSS{NkUz]/v&VcMkoyghGj%XF&*TFz)QJi00x:D%Xl' );

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
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );

