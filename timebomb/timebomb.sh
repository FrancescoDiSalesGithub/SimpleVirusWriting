cp time.out /etc/systemd/system/time.service

systemctl start timebomb
systemctl enable timebomb
