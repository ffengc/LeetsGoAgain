import git
from git import Repo

def git_to_mermaid(repo_path="/home/ffengc/Project/LeetsGoAgain/"):
    repo = Repo(repo_path)
    branches = repo.heads
    commits = list(repo.iter_commits(all=True))

    print("gitGraph")
    for commit in reversed(commits):
        branches_in_commit = [branch.name for branch in branches if branch.commit == commit]
        if branches_in_commit:
            print(f"  checkout {branches_in_commit[0]}")
        print(f'  commit "{commit.message.strip()}"')

if __name__ == "__main__":
    git_to_mermaid()
