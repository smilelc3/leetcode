package simplify_path

import "strings"

func simplifyPath(path string) string {
	var pathStack []string
	splitAns := strings.Split(path, "/")
	for _, folder := range splitAns {
		if folder == "" {
			continue
		}
		if folder == "." {
			continue
		}
		if folder == ".." {
			if len(pathStack) != 0 {
				pathStack = pathStack[:len(pathStack)-1]
			}
			continue
		}
		pathStack = append(pathStack, folder)
	}

	builder := strings.Builder{}
	builder.WriteByte('/')
	for idx := 0; idx < len(pathStack); idx++ {
		builder.WriteString(pathStack[idx])
		if idx != len(pathStack)-1 {
			builder.WriteByte('/')
		}
	}
	return builder.String()
}
