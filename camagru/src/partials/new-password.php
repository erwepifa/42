<form method="POST" action="reset-password.php">
    <input hidden name="code" type="text" value="<?php echo htmlspecialchars($_GET['code']) ?>">
    <label for="password">New password</label>
    <div>
        <input name="password" type="password" id="password" placeholder="Password">
    </div>
    <label for="password-confirm">Confirmation</label>
    <div>
        <input name="password_confirm" type="password" id="password-confirm" placeholder="Password confirmation">
    </div>

    <button type="submit">Reset</button>
</form>
