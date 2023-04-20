using System;
using System.IO;
using LabCSharp.domain;
using LabCSharp.repository.MemoryRepo;
using LabCSharp.validators;

namespace LabCSharp.repository.FileRepo
{
    public delegate E ParseLineEntity<E>(string line);
    public class FileRepository<ID,E>:InMemoryRepository<ID,E> where E:Entity<ID>
    {
        protected string FileName;
        protected ParseLineEntity<E> ParseLineEntity;

        public FileRepository(Validators<E> validator, string fileName, ParseLineEntity<E> parseLineEntity) : base(validator)
        {
            FileName = fileName;
            ParseLineEntity = parseLineEntity;
            if (ParseLineEntity != null)
            {
                LoadFromFile();
            }
        }

        void LoadFromFile()
        {
            using (var fileStream = File.OpenRead(this.FileName))
            using (var streamReader = new StreamReader(fileStream))
            {
                String line;
                while ((line = streamReader.ReadLine()) != null)
                {
                    E entity = this.ParseLineEntity(line);
                    base.save(entity);
                }
            }
        }
    }
}