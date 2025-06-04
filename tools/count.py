
# yufc write for count 

def count_problems(filename):
    difficulty_counts = {'简单': 0, '中等': 0, '困难': 0}
    total = 0

    with open(filename, 'r', encoding='utf-8') as file:
        for line in file:
            line = line.strip()
            if not line:
                continue
            
            # 处理中英文逗号混用
            line = line.replace('，', ',')
            parts = line.rsplit(',', 1)  # 从右侧分割一次
            
            if len(parts) == 2:
                difficulty = parts[1].strip()
                if difficulty in difficulty_counts:
                    difficulty_counts[difficulty] += 1
                    total += 1

    return total, difficulty_counts

def main():
    import sys
    if len(sys.argv) < 2:
        print("Please input the file name")
        return
        
    filename = sys.argv[1]
    total, counts = count_problems(filename)
    
    print(f"总数: {total}")
    for difficulty, count in counts.items():
        print(f"{difficulty}: {count}")

if __name__ == "__main__":
    main()
