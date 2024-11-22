#!/bin/bash

# Get the message from the first argument
ALERT_MESSAGE="$1"

# Display the pop-up notification
notify-send "Weather Alert" "$ALERT_MESSAGE"
