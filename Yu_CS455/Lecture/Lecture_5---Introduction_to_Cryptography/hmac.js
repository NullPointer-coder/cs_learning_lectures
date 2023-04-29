const { createHmac } = require('crypto');

const key1 = 'one-password';
const message = 'boo shoes';

const hmac1 = createHmac('sha256', key1).update(message).digest('hex');

console.log(hmac1);

const key2 = 'other-password';
const hmac2 = createHmac('sha256', key2).update(message).digest('hex');

console.log(hmac2);
