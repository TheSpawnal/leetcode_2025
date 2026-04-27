import itertools

def solve_numbers(numbers, target, epsilon=1e-9):
    # Chaque élément est stocké sous forme (valeur, "chaîne de l'expression")
    numbers_with_expr = [(float(n), str(n)) for n in numbers]

    def backtrack(current_list):
        # 1. Vérifier si l'un des nombres actuels est égal à la cible
        for val, expr in current_list:
            if abs(val - target) < epsilon:
                return expr

        # 2. Si on n'a plus qu'un nombre et que ce n'est pas la cible, on s'arrête
        if len(current_list) <= 1:
            return None

        # 3. Essayer toutes les paires possibles de nombres dans la liste
        for i, j in itertools.permutations(range(len(current_list)), 2):
            n1, expr1 = current_list[i]
            n2, expr2 = current_list[j]

            # On crée une nouvelle liste sans les deux nombres choisis
            remaining = [current_list[k] for k in range(len(current_list)) if k != i and k != j]

            # Définir les opérations possibles
            ops = [
                (n1 + n2, f"({expr1} + {expr2})"),
                (n1 - n2, f"({expr1} - {expr2})"),
                (n1 * n2, f"({expr1} * {expr2})")
            ]
            if abs(n2) > epsilon: # Éviter la division par zéro
                ops.append((n1 / n2, f"({expr1} / {expr2})"))

            for res_val, res_expr in ops:
                result = backtrack(remaining + [(res_val, res_expr)])
                if result:
                    return result
        
        return None

    return backtrack(numbers_with_expr)

# --- Configuration du problème ---
nombres_proposes = [2.5, 3.7, 4.8, 5, 9.2, 12.3]
cible = 15

solution = solve_numbers(nombres_proposes, cible)

if solution:
    print(f"🎉 Solution trouvée ! \nL'expression est : {solution} = {cible}")
else:
    print("Désolé, aucune solution n'a été trouvée avec ces nombres.")