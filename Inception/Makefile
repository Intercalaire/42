LOGIN	= vgodart

all: up

up:
	@mkdir -p /home/$(LOGIN)/data
	@mkdir -p /home/$(LOGIN)/data/mariadb
	@mkdir -p /home/$(LOGIN)/data/wordpress
	@docker compose -f ./srcs/docker-compose.yml up -d

down:
	@printf "\n🔧 $(_GREEN)Down containers$(_RESET) 🔧\n\n"
	@docker compose -f ./srcs/docker-compose.yml down

clean: down
	@printf "\n🔧 $(_GREEN)Delete /home/$(LOGIN)/data$(_RESET) 🔧\n\n"
	@rm -rf /home/$(LOGIN)/data

fclean: clean
	@printf "\n🔧 $(_GREEN)Delete containers images$(_RESET) 🔧\n\n"
	@docker system prune -af

re: fclean all

.PHONY:
	all up down clean fclean re