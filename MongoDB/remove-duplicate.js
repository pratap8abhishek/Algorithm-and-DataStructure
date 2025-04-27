const removeDuplicates = async (Model, field) => {
    // Step 1: Find duplicate values
    const duplicates = await Model.aggregate([
      {
        $group: {
          _id: `$${field}`,
          ids: { $push: '$_id' },
          count: { $sum: 1 }
        }
      },
      { $match: { count: { $gt: 1 } } }
    ]);
  
    // Step 2: Remove all except one for each duplicate
    for (const item of duplicates) {
      const idsToRemove = item.ids.slice(1); // keep the first, remove the rest
      await Model.deleteMany({ _id: { $in: idsToRemove } });
    }
  
    console.log('Duplicate removal complete.');
  };
  