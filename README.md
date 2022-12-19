# 🗣 Subject &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Philosophers

<br>
<table>
  <tr>
    <td>Program &nbsp;name</td>
    <td>philo</td>
  </tr>
  <tr>
    <td>Turn in files</td>
    <td>Makefile, &nbsp;*.h, &nbsp;*.c, &nbsp;in&nbsp; directory &nbsp;philo/</td>
  </tr>
  <tr>
    <td>Makefile</td>
    <td>NAME, &nbsp;all, &nbsp;clean, &nbsp;fclean, &nbsp;re</td>
  </tr>
  <tr>
    <td>Arguments</td>
    <td>number_of_philosophers &nbsp;time_to_die &nbsp;time_to_eat &nbsp;time_to_sleep<br>[number_of_times_each_philosopher_must_eat]</td>
  </tr>
  <tr>
    <td>External &nbsp;functs.</td>
    <td>memset, &nbsp;printf, &nbsp;malloc, &nbsp;free, &nbsp;write,&nbsp; usleep, &nbsp;gettimeofday,<br>pthread_create, &nbsp;pthread_detach, &nbsp;pthread_join, &nbsp;pthread_mutex_init,<br>pthread_mutex_destroy,&nbsp; pthread_mutex_lock, &nbsp;pthread_mutex_unlock</td>
  </tr>
  <tr>
    <td>Libft&nbsp; authorized</td>
    <td>No</td>
  </tr>
  <tr>
    <td>Description</td>
    <td>Philosophers &nbsp;with &nbsp;threads &nbsp;and &nbsp;mutexes</td>
  </tr>
</table>

<br>
The &nbsp;specific &nbsp;rules &nbsp;for &nbsp;the&nbsp; mandatory &nbsp;part &nbsp;are:<br>
<ul>
<li>Each &nbsp;philosopher &nbsp;should&nbsp; be&nbsp; a &nbsp;thread.
<li>There &nbsp;is &nbsp;one &nbsp;fork &nbsp;between &nbsp;each &nbsp;pair &nbsp;of &nbsp;philosophers. &nbsp;Therefore, &nbsp;if &nbsp;there &nbsp;are &nbsp;several&nbsp;
philosophers, &nbsp;each&nbsp; philosopher&nbsp; has &nbsp;a &nbsp;fork &nbsp;on &nbsp;their &nbsp;left &nbsp;side &nbsp;and &nbsp;a &nbsp;fork &nbsp;on &nbsp;their &nbsp;right&nbsp;
side. &nbsp;If &nbsp;there &nbsp;is&nbsp; only &nbsp;one &nbsp;philosopher, &nbsp;there &nbsp;should &nbsp;be&nbsp; only&nbsp; one &nbsp;fork &nbsp;on &nbsp;the &nbsp;table.
<li>To&nbsp; prevent &nbsp;philosophers&nbsp; from &nbsp;duplicating &nbsp;forks, &nbsp;you &nbsp;should&nbsp; protect &nbsp;the &nbsp;forks&nbsp; state&nbsp;
with&nbsp; a &nbsp;mutex &nbsp;for&nbsp; each&nbsp; of &nbsp;them.
</ul>

<br>
<h2>Global &nbsp;rules</h2>

<br>
<ul>
<li>Global &nbsp;variables&nbsp; are &nbsp;forbidden!
<li>Your(s) &nbsp;program(s)&nbsp; should &nbsp;take &nbsp;the&nbsp; following &nbsp;arguments:<br>
<b>number_of_philosophers &nbsp;time_to_die&nbsp; time_to_eat&nbsp; time_to_sleep&nbsp;
[number_of_times_each_philosopher_must_eat]</b>
<ul>
<li><b>number_of_philosophers</b>: &nbsp;The &nbsp;number &nbsp;of&nbsp; philosophers &nbsp;and &nbsp;also &nbsp;the &nbsp;number&nbsp;
of &nbsp;forks.
<li><b>time_to_die</b> &nbsp;(in &nbsp;milliseconds): &nbsp;If &nbsp;a &nbsp;philosopher &nbsp;didn’t &nbsp;start &nbsp;eating &nbsp;time_to_die&nbsp;
milliseconds &nbsp;since &nbsp;the &nbsp;beginning &nbsp;of &nbsp;their &nbsp;last &nbsp;meal &nbsp;or &nbsp;the &nbsp;beginning &nbsp;of &nbsp;the &nbsp;simulation, &nbsp;they &nbsp;die.
<li><b>time_to_eat</b> &nbsp;(in &nbsp;milliseconds): &nbsp;The &nbsp;time &nbsp;it &nbsp;takes &nbsp;for &nbsp;a &nbsp;philosopher &nbsp;to &nbsp;eat.
During &nbsp;that &nbsp;time, &nbsp;they &nbsp;will &nbsp;need &nbsp;to &nbsp;hold&nbsp; two &nbsp;forks.
<li><b>time_to_sleep</b> &nbsp;(in &nbsp;milliseconds): &nbsp;The &nbsp;time &nbsp;a &nbsp;philosopher &nbsp;will &nbsp;spend &nbsp;sleeping.
<li><b>number_of_times_each_philosopher_must_eat</b> &nbsp;(optional &nbsp;argument): &nbsp;If &nbsp;all&nbsp;
philosophers &nbsp;have &nbsp;eaten &nbsp;at &nbsp;least&nbsp; number_of_times_each_philosopher_must_eat&nbsp;
times,&nbsp; the&nbsp; simulation &nbsp;stops. &nbsp;If &nbsp;not &nbsp;specified,&nbsp; the &nbsp;simulation &nbsp;stops&nbsp; when&nbsp; a&nbsp;
philosopher &nbsp;dies.
</ul>
<li>Each &nbsp;philosopher &nbsp;has &nbsp;a &nbsp;number&nbsp; ranging &nbsp;from &nbsp;1 &nbsp;to&nbsp; number_of_philosophers.
<li>Philosopher &nbsp;number&nbsp; 1 &nbsp;sits&nbsp; next &nbsp;to&nbsp; philosopher&nbsp; number&nbsp; number_of_philosophers.&nbsp;
Any &nbsp;other&nbsp; philosopher&nbsp; number&nbsp; N &nbsp;sits &nbsp;between &nbsp;philosopher &nbsp;number &nbsp;N &nbsp;- &nbsp;1 &nbsp;and &nbsp;philosopher &nbsp;number &nbsp;N &nbsp;+ &nbsp;1.
</ul>

<br>
About &nbsp;the &nbsp;logs &nbsp;of &nbsp;your &nbsp;program:<br>
<ul>
<li>Any &nbsp;state &nbsp;change&nbsp; of&nbsp; a &nbsp;philosopher&nbsp; must&nbsp; be&nbsp; formatted &nbsp;as &nbsp;follows:
<ul>
<li>timestamp_in_ms&nbsp; X &nbsp;has &nbsp;taken&nbsp; a &nbsp;fork
<li>timestamp_in_ms &nbsp;X &nbsp;is &nbsp;eating
<li>timestamp_in_ms &nbsp;X &nbsp;is &nbsp;sleeping
<li>timestamp_in_ms &nbsp;X &nbsp;is &nbsp;thinking
<li>timestamp_in_ms &nbsp;X &nbsp;died
</ul>
<i>Replace</i> &nbsp;timestamp_in_ms &nbsp;<i>with&nbsp; the &nbsp;current &nbsp;timestamp &nbsp;in&nbsp; milliseconds</i>&nbsp;
and &nbsp;X&nbsp; <i>with &nbsp;the &nbsp;philosopher &nbsp;number</i>.
<li>A &nbsp;displayed &nbsp;state &nbsp;message &nbsp;should &nbsp;not &nbsp;be &nbsp;mixed &nbsp;up &nbsp;with&nbsp; another&nbsp; message.
<li>A &nbsp;message&nbsp; announcing&nbsp; a &nbsp;philosopher&nbsp; died&nbsp; should&nbsp; be&nbsp; displayed &nbsp;no &nbsp;more &nbsp;than &nbsp;10&nbsp; ms&nbsp;
after &nbsp;the actual&nbsp; death&nbsp; of&nbsp; the&nbsp; philosopher.
<li>Again, &nbsp;philosophers &nbsp;should &nbsp;avoid&nbsp; dying!
</ul>
