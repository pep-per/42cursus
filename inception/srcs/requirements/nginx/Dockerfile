FROM alpine:stable
LABEL maintainer="jiyeolee"
RUN apk-get update \
		&& apk-get install nginx
RUN echo "TEST" > /var/www/html/index.html

COPY srcs/requirements/nginx/nginx.conf /
EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]

