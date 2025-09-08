# This PowerShell script uses git to synchronize changes between the local and remote GitHub repository.
# TODO: Ask copilot chat to review the script and suggest improvements.

# Add all changes
git add .

# Commit changes
git commit -m "Updated"

# Pull latest changes from main branch
git pull origin main

# Push changes to remote repository
git push

# Check if the push was successful
if ($LASTEXITCODE -eq 0) {
    Write-Host "Changes pushed successfully to the remote repository."
} else {
    Write-Host "Failed to push changes to the remote repository. Please check for conflicts or errors."
}
