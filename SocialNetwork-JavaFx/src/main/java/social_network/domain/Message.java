package social_network.domain;

import java.time.LocalDateTime;

public class Message {
    private int id;
    private String message;
    private String from;
    private String to;
     LocalDateTime time = LocalDateTime.now();

    public Message(int id, String message, String from, String to) {
       this.id = id;
        this.message = message;
        this.from = from;
        this.to = to;

    }
    public Message(int id, String message, String from, String to, LocalDateTime time) {
        this.id = id;
        this.message = message;
        this.from = from;
        this.to = to;
        this.time=time;

    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getFrom() {
        return from;
    }

    public void setFrom(String from) {
        this.from = from;
    }

    public String getTo() {
        return to;
    }

    public void setTo(String to) {
        this.to = to;
    }

    public LocalDateTime getTime() {
        return time;
    }

    public void setTime(LocalDateTime time) {
        this.time = time;
    }
}
