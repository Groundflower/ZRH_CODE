import pygame
import random
import math

# 初始化pygame
pygame.init()

# 屏幕设置
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("爱心圣诞树粒子动画")
clock = pygame.time.Clock()

# 颜色定义
BLACK = (0, 0, 0)
PINK = (255, 105, 180)
WHITE = (255, 255, 255)

# 粒子类
class Particle:
    def __init__(self, x, y, color, size, speed, direction):
        self.x = x
        self.y = y
        self.color = color
        self.size = size
        self.speed = speed
        self.direction = direction  # 角度（弧度）
        self.alpha = 255  # 透明度
        self.fade_speed = random.uniform(1, 3)  # 褪色速度

    def update(self):
        # 粒子移动（沿方向）
        self.x += math.cos(self.direction) * self.speed
        self.y += math.sin(self.direction) * self.speed
        # 粒子褪色
        self.alpha = max(0, self.alpha - self.fade_speed)
        # 粒子缩小
        self.size = max(0, self.size - 0.05)

    def draw(self, surface):
        if self.alpha > 0 and self.size > 0:
            # 绘制带透明度的粒子
            s = pygame.Surface((self.size * 2, self.size * 2), pygame.SRCALPHA)
            pygame.draw.circle(s, (*self.color, self.alpha), (self.size, self.size), self.size)
            surface.blit(s, (self.x - self.size, self.y - self.size))

# 生成圣诞树粒子的函数
def create_tree_particles(particles, x, y, color):
    num_particles = 50
    for _ in range(num_particles):
        # 随机方向（围绕中心点的发散角度）
        direction = random.uniform(0, math.pi * 2)
        # 随机速度和大小
        speed = random.uniform(1, 3)
        size = random.uniform(2, 5)
        particles.append(Particle(x, y, color, size, speed, direction))

# 生成爱心的函数
def create_heart(particles, x, y):
    # 爱心的简易数学公式（参数方程）
    t = random.uniform(0, math.pi * 2)
    heart_x = 16 * math.sin(t) ** 3
    heart_y = 13 * math.cos(t) - 5 * math.cos(2 * t) - 2 * math.cos(3 * t) - math.cos(4 * t)
    # 映射到屏幕坐标并生成粒子
    px = x + heart_x * 3
    py = y + heart_y * 3
    size = random.uniform(3, 6)
    speed = random.uniform(0.5, 2)
    direction = random.uniform(0, math.pi * 2)
    particles.append(Particle(px, py, PINK, size, speed, direction))

# 粒子列表
particles = []
# 文字渲染
font = pygame.font.SysFont(None, 48)
text = font.render("Merry Christmas", True, WHITE)
text_rect = text.get_rect(topleft=(20, 20))

# 主循环
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill(BLACK)

    # 绘制背景星星
    for _ in range(50):
        star_x = random.randint(0, WIDTH)
        star_y = random.randint(0, HEIGHT)
        star_size = random.uniform(1, 3)
        pygame.draw.circle(screen, WHITE, (star_x, star_y), star_size)

    # 生成圣诞树粒子（中心在屏幕中下部）
    tree_center_x = WIDTH // 2
    tree_center_y = HEIGHT // 2 + 50
    create_tree_particles(particles, tree_center_x, tree_center_y, PINK)

    # 生成顶部爱心粒子
    heart_center_x = WIDTH // 2
    heart_center_y = HEIGHT // 2 - 100
    create_heart(particles, heart_center_x, heart_center_y)

    # 更新并绘制所有粒子
    for p in particles[:]:
        p.update()
        p.draw(screen)
        if p.alpha <= 0 or p.size <= 0:
            particles.remove(p)

    # 绘制文字
    screen.blit(text, text_rect)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
print("you are the end of the my lover")