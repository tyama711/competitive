#! /usr/bin/env python3
import requests
import time
import os
import urllib.parse
import subprocess
import sys

ship = 4
# 文字列"<FLAG>4"のハッシュ値
signature = '662c1f9223674b42a1ac767aea7096a7eefe55f7f8ef99ba441ce61b065bda6b9b9c242a18bf17aea164aa76aed60e9cb586812a74d346b0f17bb61b5dbba988'

# hashpumpを実行
cmdline = 'hashpump -s {0} -d {1} -k 21 -a,10'.format(signature, ship)
p = subprocess.Popen (cmdline, shell=True, stdin=subprocess.PIPE,
                      stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                      close_fds=True)
(stdouterr, stdin) = (p.stdout, p.stdin)
hash = stdouterr.read().decode('utf-8').split('\n')


# "Gacha"を実行
url = 'http://ctfq.sweetduet.info:10080/~q31/kangacha.php'
payload = {'submit': 'Gacha'}
headers = {'content-type': 'application/x-www-form-urlencoded'}
s = requests.session()
r = s.post(
    url,
    data=payload,
    headers=headers,
    cookies={
        'ship':hash[1].replace('\\x', '%').upper(),
        'signature':hash[0]
    }
)

print(r.text)
