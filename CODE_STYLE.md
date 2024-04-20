# Naming conventions

Abbreviations use same capitalization for each letter (e.g. UI or ui, but no Ui)

## Code

| Item                              | Style                   |
|-----------------------------------|-------------------------|
| Class / struct                    | PascalCase              |
| Enum                              | PascalCase              |
| Method                            | PascalCase              |
| Function                          | PascalCase              |
| Variable                          | camelCase               |
| Constant (constexpr/static const) | UPPER_SNAKE_CASE        |
| Enum member                       | UPPER_SNAKE_CASE        |
| Namespace                         | snake_case              |
| ImGui IDs                         | Capitalized with spaces |

## Files

Use class name (PascalCase) directly, or camelCase names if file does not have a class (e.g. ImGui widget)