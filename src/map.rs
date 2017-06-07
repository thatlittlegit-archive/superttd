pub struct Tile {
    ground_level: u8,
    building: u16
}
pub struct Map {
    dimensions: (u16, u16),
    contents: Vec<(u16, u16, Tile)>
}

impl Map {
    pub fn random() -> Map {
        let mut x = Vec::new();
        for q in 0..64 {
            for i in 0..64 {
                x.push((q, i, Tile {ground_level: 1, building: 1}));
            }
        }
        Map { dimensions:(1, 1), contents:x }
    }
}
