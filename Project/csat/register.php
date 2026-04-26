<!DOCTYPE html>
<html lang="en" data-bs-theme="dark">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Create Account — CSAT</title>
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
      --ok:      #28c840;
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
        max-width: 440px;
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
      font-size: 2.3rem;
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
      margin-bottom: 1.75rem;
      font-weight: 400;
    }

    .disclaimer-sm {
      background: rgba(255,77,109,.06);
      border: 1px solid rgba(255,77,109,.2);
      border-radius: 6px;
      padding: .75rem 1rem;
      font-size: .78rem;
      color: #d08090;
      line-height: 1.6;
      display: flex;
      gap: .6rem;
    }

    .disclaimer-sm i { color: var(--danger); flex-shrink: 0; margin-top: .1rem; }

    /* ── AUTH CARD ── */
    .auth-card {
      background: var(--surface);
      border: 1px solid var(--border);
      border-radius: 14px;
      padding: 2.5rem 2rem;
      width: 100%;
      max-width: 440px;
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

    /* ── FORM ── */
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

    .form-control.is-valid {
      border-color: var(--ok) !important;
      background-image: none !important;
    }

    .form-control.is-invalid {
      border-color: var(--danger) !important;
      background-image: none !important;
    }

    .field-hint {
      font-size: .75rem;
      color: var(--muted);
      margin-top: .3rem;
    }

    .field-hint.ok { color: var(--ok); }
    .field-hint.err { color: var(--danger); }

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

    /* password toggle */
    .pw-wrap { position: relative; }

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

    /* ── PASSWORD STRENGTH ── */
    .pw-strength-bar {
      display: flex;
      gap: 4px;
      margin-top: .5rem;
    }

    .pw-seg {
      flex: 1;
      height: 3px;
      border-radius: 2px;
      background: var(--surface2);
      transition: background .3s;
    }

    .pw-seg.active-weak   { background: var(--danger); }
    .pw-seg.active-fair   { background: var(--warn); }
    .pw-seg.active-good   { background: #febc2e; }
    .pw-seg.active-strong { background: var(--ok); }

    .pw-strength-label {
      font-size: .72rem;
      color: var(--muted);
      margin-top: .3rem;
    }

    /* ── CONSENT CHECKBOX ── */
    .form-check-input {
      background-color: var(--surface2) !important;
      border-color: var(--border) !important;
      width: 16px !important;
      height: 16px !important;
      flex-shrink: 0;
      margin-top: .15rem;
    }

    .form-check-input:checked {
      background-color: var(--cyan) !important;
      border-color: var(--cyan) !important;
    }

    .form-check-label {
      font-size: .8rem;
      color: var(--muted);
      line-height: 1.6;
    }

    .form-check-label a {
      color: var(--cyan);
      text-decoration: none;
    }

    /* ── SUBMIT ── */
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
    .btn-submit:disabled { opacity: .4; cursor: not-allowed; transform: none; }

    /* ── OR / LOGIN LINK ── */
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

    .login-prompt {
      text-align: center;
      font-size: .84rem;
      color: var(--muted);
    }

    .login-prompt a {
      color: var(--cyan);
      text-decoration: none;
      font-weight: 700;
    }

    .login-prompt a:hover { text-decoration: underline; }

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

    .alert-csat-ok {
      background: rgba(40,200,64,.08);
      border: 1px solid rgba(40,200,64,.3);
      border-radius: 6px;
      padding: .75rem 1rem;
      font-size: .84rem;
      color: #7ee890;
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

  <div class="glow-blob" style="width:400px;height:400px;background:rgba(0,245,212,.05);top:0;left:-150px;"></div>
  <div class="glow-blob" style="width:350px;height:350px;background:rgba(244,162,97,.04);bottom:0;right:-100px;"></div>

  <!-- NAVBAR -->
  <nav class="navbar">
    <div class="container">
      <a class="navbar-brand" href="index.html">CSAT<span style="color:var(--text);">.</span></a>
    </div>
  </nav>

  <!-- AUTH LAYOUT -->
  <div class="auth-wrap">
    <div class="d-flex align-items-start gap-5" style="width:100%;max-width:940px;">

      <!-- LEFT PANEL -->
      <div class="auth-panel-left">
        <p class="auth-eyebrow">New Account</p>
        <h2 class="auth-headline">Start Auditing<br>Your <span class="accent">Posture.</span></h2>
        <p class="auth-sub">
          Free to use. No credit card. Just create an account and submit your first target in under two minutes.
        </p>

        <div class="disclaimer-sm">
          <i class="bi bi-exclamation-triangle-fill"></i>
          <span>
            By creating an account you agree to only scan domains, IPs, and URLs
            that you own or have explicit written authorization to test.
            Unauthorized scanning is illegal and your account will be suspended.
          </span>
        </div>
      </div>

      <!-- AUTH CARD -->
      <div class="auth-card">
        <p class="card-title-mono">New Account</p>
        <h1 class="card-heading">Create Account</h1>

        <?php if (!empty($error)): ?>
        <div class="alert-csat">
          <i class="bi bi-exclamation-circle"></i>
          <?= htmlspecialchars($error) ?>
        </div>
        <?php endif; ?>

        <?php if (!empty($success)): ?>
        <div class="alert-csat-ok">
          <i class="bi bi-check-circle"></i>
          <?= htmlspecialchars($success) ?>
        </div>
        <?php endif; ?>

        <form action="register.php" method="POST" novalidate id="regForm">
          <input type="hidden" name="csrf_token" value="<?= $_SESSION['csrf_token'] ?? '' ?>">

          <!-- Username -->
          <div class="mb-3">
            <label class="form-label" for="username">Username</label>
            <div class="input-group">
              <span class="input-group-text"><i class="bi bi-person"></i></span>
              <input
                type="text"
                class="form-control"
                id="username"
                name="username"
                placeholder="yourhandle"
                value="<?= htmlspecialchars($_POST['username'] ?? '') ?>"
                required
                autocomplete="username"
                minlength="3"
                maxlength="30"
                pattern="[a-zA-Z0-9_]+"
              />
            </div>
            <p class="field-hint" id="usernameHint">3–30 chars, letters, numbers, underscores only.</p>
          </div>

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
                  placeholder="Min. 8 characters"
                  required
                  autocomplete="new-password"
                  style="padding-right:3rem !important;"
                />
              </div>
              <button type="button" class="toggle-pw" id="togglePw" tabindex="-1">
                <i class="bi bi-eye" id="eyeIcon"></i>
              </button>
            </div>
            <!-- Strength bar -->
            <div class="pw-strength-bar" id="strengthBar">
              <div class="pw-seg" id="seg1"></div>
              <div class="pw-seg" id="seg2"></div>
              <div class="pw-seg" id="seg3"></div>
              <div class="pw-seg" id="seg4"></div>
            </div>
            <p class="pw-strength-label" id="strengthLabel">Enter a password</p>
          </div>

          <!-- Confirm Password -->
          <div class="mb-3">
            <label class="form-label" for="confirm_password">Confirm Password</label>
            <div class="input-group">
              <span class="input-group-text"><i class="bi bi-lock-fill"></i></span>
              <input
                type="password"
                class="form-control"
                id="confirm_password"
                name="confirm_password"
                placeholder="Repeat your password"
                required
                autocomplete="new-password"
              />
            </div>
            <p class="field-hint" id="matchHint"></p>
          </div>

          <!-- Consent checkbox -->
          <div class="form-check d-flex align-items-start gap-2 mb-2">
            <input class="form-check-input" type="checkbox" id="consent" name="consent" required />
            <label class="form-check-label" for="consent">
              I agree to only scan targets I own or have <strong>explicit written authorization</strong> to test.
              I understand unauthorized scanning may be illegal.
            </label>
          </div>

          <div class="form-check d-flex align-items-start gap-2">
            <input class="form-check-input" type="checkbox" id="terms" name="terms" required />
            <label class="form-check-label" for="terms">
              I accept the <a href="#">Terms of Use</a> and <a href="#">Privacy Policy</a>.
            </label>
          </div>

          <!-- Submit -->
          <button type="submit" class="btn-submit" id="submitBtn">
            <i class="bi bi-person-plus"></i> Create Account
          </button>
        </form>

        <div class="or-divider">already have an account?</div>

        <p class="login-prompt">
          <a href="login.php"><i class="bi bi-box-arrow-in-right"></i> Sign in instead</a>
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
    /* ── PASSWORD VISIBILITY ── */
    document.getElementById('togglePw').addEventListener('click', () => {
      const pw = document.getElementById('password');
      const ic = document.getElementById('eyeIcon');
      const isHidden = pw.type === 'password';
      pw.type = isHidden ? 'text' : 'password';
      ic.className = isHidden ? 'bi bi-eye-slash' : 'bi bi-eye';
    });

    /* ── PASSWORD STRENGTH ── */
    const pwInput = document.getElementById('password');
    const segs    = [1,2,3,4].map(i => document.getElementById('seg'+i));
    const label   = document.getElementById('strengthLabel');

    const classes = ['active-weak','active-fair','active-good','active-strong'];
    const labels  = ['Weak','Fair','Good','Strong'];
    const colors  = ['#ff4d6d','#f4a261','#febc2e','#28c840'];

    function scorePassword(pw) {
      let s = 0;
      if (pw.length >= 8)  s++;
      if (pw.length >= 12) s++;
      if (/[A-Z]/.test(pw) && /[a-z]/.test(pw)) s++;
      if (/[0-9]/.test(pw)) s++;
      if (/[^A-Za-z0-9]/.test(pw)) s++;
      return Math.min(4, Math.ceil(s * 4 / 5));
    }

    pwInput.addEventListener('input', () => {
      const pw = pwInput.value;
      if (!pw) {
        segs.forEach(s => s.className = 'pw-seg');
        label.textContent = 'Enter a password';
        label.style.color = 'var(--muted)';
        return;
      }
      const score = scorePassword(pw);
      segs.forEach((s, i) => {
        s.className = 'pw-seg' + (i < score ? ' ' + classes[score-1] : '');
      });
      label.textContent = labels[score-1];
      label.style.color = colors[score-1];
    });

    /* ── CONFIRM MATCH ── */
    const confirmPw = document.getElementById('confirm_password');
    const matchHint = document.getElementById('matchHint');

    confirmPw.addEventListener('input', checkMatch);
    pwInput.addEventListener('input', checkMatch);

    function checkMatch() {
      if (!confirmPw.value) {
        matchHint.textContent = '';
        matchHint.className = 'field-hint';
        confirmPw.classList.remove('is-valid','is-invalid');
        return;
      }
      if (pwInput.value === confirmPw.value) {
        matchHint.textContent = '✓ Passwords match';
        matchHint.className = 'field-hint ok';
        confirmPw.classList.add('is-valid');
        confirmPw.classList.remove('is-invalid');
      } else {
        matchHint.textContent = '✗ Passwords do not match';
        matchHint.className = 'field-hint err';
        confirmPw.classList.add('is-invalid');
        confirmPw.classList.remove('is-valid');
      }
    }

    /* ── USERNAME HINT ── */
    const uname = document.getElementById('username');
    const uHint = document.getElementById('usernameHint');
    const uPat  = /^[a-zA-Z0-9_]{3,30}$/;

    uname.addEventListener('input', () => {
      if (!uname.value) {
        uHint.textContent = '3–30 chars, letters, numbers, underscores only.';
        uHint.className = 'field-hint';
        return;
      }
      if (uPat.test(uname.value)) {
        uHint.textContent = '✓ Looks good';
        uHint.className = 'field-hint ok';
      } else {
        uHint.textContent = '✗ Only letters, numbers, and underscores allowed.';
        uHint.className = 'field-hint err';
      }
    });
  </script>
</body>
</html>
