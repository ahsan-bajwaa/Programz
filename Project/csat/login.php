<!DOCTYPE html>
<html lang="en" data-bs-theme="dark">
<head>
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title>Sign In — CSAT</title>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
<link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet" />
<link href="https://fonts.googleapis.com/css2?family=Share+Tech+Mono&family=Syne:wght@400;700;800&display=swap" rel="stylesheet" />
<style>
:root {
    --cyan:    #00f5d4;
    --cyan-dim:#00b89f;
    --bg:      #070d14;
    --surface: #0d1825;
    --surface2:#111f30;
    --border:  #1a3048;
    --text:    #cdd9e5;
    --muted:   #5a7a96;
    --danger:  #ff4d6d;
    --warn:    #f4a261;
}

*, *::before, *::after { box-sizing: border-box; }

body {
    font-family: 'Syne', sans-serif;
    background: var(--bg);
    color: var(--text);
    min-height: 100vh;
    display: flex;
    flex-direction: column;
    overflow-x: hidden;
}

body::before {
    content: '';
    position: fixed;
    inset: 0;
    background-image:
    linear-gradient(rgba(0,245,212,.025) 1px, transparent 1px),
    linear-gradient(90deg, rgba(0,245,212,.025) 1px, transparent 1px);
    background-size: 48px 48px;
    pointer-events: none;
    z-index: 0;
}

/* ── NAVBAR ── */
.navbar {
    background: rgba(7,13,20,.85) !important;
    backdrop-filter: blur(12px);
    border-bottom: 1px solid var(--border);
    padding: .9rem 0;
    position: relative; z-index: 10;
}

.navbar-brand {
    font-family: 'Share Tech Mono', monospace;
    font-size: 1.2rem;
    color: var(--cyan) !important;
    letter-spacing: .08em;
    text-decoration: none;
}

/* ── MAIN LAYOUT ── */
.auth-wrap {
    flex: 1;
    display: flex;
    align-items: center;
    justify-content: center;
    padding: 3rem 1rem;
    position: relative; z-index: 1;
}

/* ── LEFT PANEL ── */
.auth-panel-left {
    display: none;
}

@media (min-width: 992px) {
    .auth-panel-left {
        display: flex;
        flex-direction: column;
        justify-content: center;
        padding: 3rem 2.5rem;
        flex: 1;
        max-width: 460px;
    }
}

.auth-eyebrow {
    font-family: 'Share Tech Mono', monospace;
    font-size: .72rem;
    letter-spacing: .2em;
    color: var(--cyan);
    text-transform: uppercase;
    margin-bottom: 1.2rem;
    display: flex;
    align-items: center;
    gap: .5rem;
}

.auth-eyebrow::before {
    content: '';
    display: inline-block;
    width: 24px; height: 1px;
    background: var(--cyan);
}

.auth-headline {
    font-size: 2.4rem;
    font-weight: 800;
    color: #fff;
    line-height: 1.1;
    margin-bottom: 1rem;
}

.auth-headline .accent { color: var(--cyan); }

.auth-sub {
    color: var(--muted);
    font-size: .9rem;
    line-height: 1.75;
    margin-bottom: 2rem;
    font-weight: 400;
}

.mini-feature {
    display: flex;
    align-items: center;
    gap: .75rem;
    margin-bottom: .75rem;
    font-size: .85rem;
    color: var(--muted);
}

.mini-feature i { color: var(--cyan); font-size: .9rem; }

/* ── CARD ── */
.auth-card {
    background: var(--surface);
    border: 1px solid var(--border);
    border-radius: 14px;
    padding: 2.5rem 2rem;
    width: 100%;
    max-width: 420px;
}

.card-title-mono {
    font-family: 'Share Tech Mono', monospace;
    font-size: .72rem;
    letter-spacing: .18em;
    color: var(--cyan);
    text-transform: uppercase;
    margin-bottom: .5rem;
}

.card-heading {
    font-size: 1.6rem;
    font-weight: 800;
    color: #fff;
    margin-bottom: 1.75rem;
}

/* ── FORM ELEMENTS ── */
.form-label {
    font-size: .78rem;
    font-weight: 700;
    letter-spacing: .06em;
    text-transform: uppercase;
    color: var(--muted);
    margin-bottom: .45rem;
}

.form-control {
    background: var(--surface2) !important;
    border: 1px solid var(--border) !important;
    border-radius: 6px !important;
    color: var(--text) !important;
    padding: .75rem 1rem !important;
    font-size: .9rem !important;
    font-family: 'Syne', sans-serif;
    transition: border-color .2s !important;
}

.form-control:focus {
    border-color: var(--cyan) !important;
    box-shadow: 0 0 0 3px rgba(0,245,212,.1) !important;
    outline: none !important;
}

.form-control::placeholder { color: var(--muted) !important; }

.input-group-text {
    background: var(--surface2) !important;
    border: 1px solid var(--border) !important;
    border-right: none !important;
    color: var(--muted) !important;
    border-radius: 6px 0 0 6px !important;
    padding: .75rem .9rem !important;
}

.input-group .form-control {
    border-left: none !important;
    border-radius: 0 6px 6px 0 !important;
}

.input-group:focus-within .input-group-text {
    border-color: var(--cyan) !important;
    color: var(--cyan) !important;
}

.input-group:focus-within .form-control {
    border-color: var(--cyan) !important;
}

/* toggle password btn */
.toggle-pw {
    background: transparent;
    border: none;
    color: var(--muted);
    cursor: pointer;
    padding: 0 .75rem;
    position: absolute;
    right: 0;
    top: 50%;
    transform: translateY(-50%);
    z-index: 5;
    transition: color .2s;
}

.toggle-pw:hover { color: var(--cyan); }

.pw-wrap { position: relative; }

/* ── REMEMBER / FORGOT ── */
.form-check-input {
    background-color: var(--surface2) !important;
    border-color: var(--border) !important;
    width: 15px !important;
    height: 15px !important;
}

.form-check-input:checked {
    background-color: var(--cyan) !important;
    border-color: var(--cyan) !important;
}

.form-check-label {
    font-size: .82rem;
    color: var(--muted);
    cursor: pointer;
}

.forgot-link {
    font-size: .82rem;
    color: var(--muted);
    text-decoration: none;
    transition: color .2s;
}

.forgot-link:hover { color: var(--cyan); }

/* ── SUBMIT BTN ── */
.btn-submit {
    width: 100%;
    background: var(--cyan);
    color: var(--bg);
    font-weight: 800;
    font-size: .9rem;
    letter-spacing: .06em;
    text-transform: uppercase;
    padding: .85rem;
    border: none;
    border-radius: 6px;
    cursor: pointer;
    transition: opacity .2s, transform .2s;
    display: flex;
    align-items: center;
    justify-content: center;
    gap: .5rem;
    margin-top: 1.5rem;
}

.btn-submit:hover { opacity: .85; transform: translateY(-1px); }
.btn-submit:active { transform: translateY(0); }

/* ── DIVIDER ── */
.or-divider {
    display: flex;
    align-items: center;
    gap: 1rem;
    margin: 1.5rem 0;
    font-size: .75rem;
    color: var(--muted);
    letter-spacing: .08em;
    text-transform: uppercase;
}

.or-divider::before, .or-divider::after {
    content: '';
    flex: 1;
    height: 1px;
    background: var(--border);
}

/* ── REGISTER LINK ── */
.register-prompt {
    text-align: center;
    font-size: .84rem;
    color: var(--muted);
    margin-top: 1.25rem;
}

.register-prompt a {
    color: var(--cyan);
    text-decoration: none;
    font-weight: 700;
}

.register-prompt a:hover { text-decoration: underline; }

/* ── ALERT ── */
.alert-csat {
    background: rgba(255,77,109,.08);
    border: 1px solid rgba(255,77,109,.3);
    border-radius: 6px;
    padding: .75rem 1rem;
    font-size: .84rem;
    color: #e8a0ac;
    display: flex;
    align-items: center;
    gap: .6rem;
    margin-bottom: 1.25rem;
}

/* ── GLOW ── */
.glow-blob {
    position: fixed;
    border-radius: 50%;
    filter: blur(100px);
    pointer-events: none;
    z-index: 0;
}

/* ── FOOTER ── */
.auth-footer {
    position: relative; z-index: 1;
    text-align: center;
    padding: 1.25rem;
    font-size: .75rem;
    color: var(--muted);
    border-top: 1px solid var(--border);
}
</style>
</head>
<body>

<div class="glow-blob" style="width:400px;height:400px;background:rgba(0,245,212,.05);top:-80px;right:-100px;"></div>
<div class="glow-blob" style="width:300px;height:300px;background:rgba(255,77,109,.04);bottom:0;left:-80px;"></div>

<!-- NAVBAR -->
<nav class="navbar">
<div class="container">
<a class="navbar-brand" href="index.html">CSAT<span style="color:var(--text);">.</span></a>
</div>
</nav>

<!-- AUTH LAYOUT -->
<div class="auth-wrap">
<div class="d-flex align-items-center gap-5" style="width:100%;max-width:900px;">

<!-- LEFT PANEL (desktop only) -->
<div class="auth-panel-left">
<p class="auth-eyebrow">Secure Access</p>
<h2 class="auth-headline">Welcome<br>Back to <span class="accent">CSAT.</span></h2>
<p class="auth-sub">Your scans, reports, and risk history are waiting. Sign in to continue monitoring your attack surface.</p>

<div class="mini-feature"><i class="bi bi-shield-check"></i> Real-time threat intelligence scanning</div>
<div class="mini-feature"><i class="bi bi-graph-up"></i> Risk score tracking over time</div>
<div class="mini-feature"><i class="bi bi-activity"></i> Automatic SIEM log forwarding</div>
<div class="mini-feature"><i class="bi bi-file-earmark-pdf"></i> Downloadable PDF reports</div>
</div>

<!-- AUTH CARD -->
<div class="auth-card" style="flex-shrink:0;">
<p class="card-title-mono">Authentication</p>
<h1 class="card-heading">Sign In</h1>

<!-- PHP will echo error here -->
<?php if (!empty($error)): ?>
<div class="alert-csat">
<i class="bi bi-exclamation-circle"></i>
<?= htmlspecialchars($error) ?>
</div>
<?php endif; ?>

<form action="login.php" method="POST" novalidate>
<!-- CSRF token - PHP will generate this -->
<input type="hidden" name="csrf_token" value="<?= $_SESSION['csrf_token'] ?? '' ?>">

<!-- Email -->
<div class="mb-3">
<label class="form-label" for="email">Email Address</label>
<div class="input-group">
<span class="input-group-text"><i class="bi bi-envelope"></i></span>
<input
type="email"
class="form-control"
id="email"
name="email"
placeholder="you@example.com"
value="<?= htmlspecialchars($_POST['email'] ?? '') ?>"
required
autocomplete="email"
/>
</div>
</div>

<!-- Password -->
<div class="mb-3">
<label class="form-label" for="password">Password</label>
<div class="pw-wrap">
<div class="input-group">
<span class="input-group-text"><i class="bi bi-lock"></i></span>
<input
type="password"
class="form-control"
id="password"
name="password"
placeholder="Your password"
required
autocomplete="current-password"
style="padding-right:3rem !important;"
/>
</div>
<button type="button" class="toggle-pw" id="togglePw" tabindex="-1">
<i class="bi bi-eye" id="eyeIcon"></i>
</button>
</div>
</div>

<!-- Remember / Forgot -->
<div class="d-flex justify-content-between align-items-center mb-1">
<div class="form-check">
<input class="form-check-input" type="checkbox" id="remember" name="remember">
<label class="form-check-label" for="remember">Remember me</label>
</div>
<a href="forgot.php" class="forgot-link">Forgot password?</a>
</div>

<!-- Submit -->
<button type="submit" class="btn-submit">
<i class="bi bi-box-arrow-in-right"></i> Sign In
</button>
</form>

<div class="or-divider">or</div>

<p class="register-prompt">
Don't have an account? <a href="register.php">Create one free</a>
</p>
</div>

</div>
</div>

<div class="auth-footer">
Only scan targets you own or have explicit authorization to test. &nbsp;·&nbsp;
<a href="index.html" style="color:var(--muted);text-decoration:none;">← Back to Home</a>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
<script>
const togglePw = document.getElementById('togglePw');
const pwField  = document.getElementById('password');
const eyeIcon  = document.getElementById('eyeIcon');

togglePw.addEventListener('click', () => {
    const isHidden = pwField.type === 'password';
pwField.type = isHidden ? 'text' : 'password';
eyeIcon.className = isHidden ? 'bi bi-eye-slash' : 'bi bi-eye';
});
</script>
</body>
</html>
