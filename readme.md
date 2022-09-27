## cub3D ##

🧊  
[디렉토리]  
cub3d  
|-- Makefile  
|-- asset  
|-- cub3d.h  
|-- debug  
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|-- debug.c  
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|-- debug.h  
|-- del.c  
|-- game_manager  
|-- libft  
|-- main.c  
|-- map  
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|-- invalid_map  
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|-- valid_map  
|-- mlx  
|-- parser  
|-- readme.md  
|-- structure.h  
|-- utils.c  

# flow #

1. valid_check_fill_info에서 맵 읽고 오류 체크
	1. 맵에 오류가 없으면, texture 파일 이름을 t_map_info에 담음
	2. texture 파일들 열어보고 존재 하지 않으면 오류 뱉고 종료

	1까지 norm, 누수 체크 완료

2. 이후 실행부
