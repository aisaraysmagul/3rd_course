import imaplib
import email

USER = 'albioncompany18@gmail.com'
PASSWORD = 'Albion2018'
IMAP_URL = 'imap.gmail.com'

def get_body(msg):
    if msg.is_multipart():
        return get_body(msg.get_payload(0))
    else:
        return msg.get_payload(None, True)

def get_emails(connection):
    msgs_dict = {}
    result, data = connection.uid('search', None, "ALL")
    if result == 'OK':
        for num in data[0].split():
            result, data = connection.uid('fetch', num, '(RFC822)')
            if result == 'OK':
                email_message = email.message_from_bytes(data[0][1])
                msgs_dict[email_message['From'].split(' ')[1]] = get_body(email_message)
    return msgs_dict

conn = imaplib.IMAP4_SSL(IMAP_URL)
conn.login(USER, PASSWORD)
conn.select('INBOX')

dictionary = get_emails(conn)
for msg in msgs_dict:
    print(msg, msgs_dict[msg])