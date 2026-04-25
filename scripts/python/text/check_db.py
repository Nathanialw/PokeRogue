# check_db.py
from python.data import db_manager

print("=== Database Contents ===\n")
db_manager.view_database(limit=30)

print("\n=== Model Statistics ===\n")
stats = db_manager.get_model_stats()
for stat in stats:
    if len(stat) == 4:  # Per-model stats
        model, total, avg_words, unique = stat
        print(f"{model}: {total} descriptions, {unique} creatures, {avg_words:.1f} avg words")
    else:
        print(f"Overall: {stat[0]} descriptions, {stat[3]} creatures, {stat[1]:.1f} avg words")

print(f"\nDatabase file: {db_manager.DB_FILE}")